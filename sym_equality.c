/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_equality.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:58:58 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/08 17:03:59 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "libft.h"

t_bool	symbol_are_identical(t_symbol const *sym_1,
		t_symbol const *sym_2)
{
	return (ft_strequ(sym_1->name, sym_2->name)
			&& prods_set_identical((t_prod const**)sym_1->prods,
				(t_prod const**)sym_2->prods));
}
