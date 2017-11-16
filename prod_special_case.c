/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_special_case.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:55:29 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/16 14:58:45 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"
#include "sym_interface.h"

t_prod	*get_empty_prod(void)
{
	t_prod	*prod;

	prod = create_prod();
	append_to_prod(prod, get_empty_symbol());
	return (prod);
}
