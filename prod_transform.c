/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:11:35 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/30 13:03:22 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"

t_prod	*produce_developed_prod(
		t_prod const *developed_symbol,
		t_prod const *to_develop)
{
	t_prod	*to_append;
	t_prod	*append_to;
	t_prod	*final_new;

	to_append = dup_prod(developed_symbol);
	append_to = dup_prod(to_develop);
	if (to_append == NULL || append_to == NULL)
	{
		destroy_prod(&to_append);
		destroy_prod(&append_to);
		final_new = NULL;
	}
	else
		final_new = join_prods(to_append, append_to);
	return (final_new);
}
