/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:49:32 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/28 13:00:24 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "libft.h"

static t_bool	equ(void const *prod_1, void const *prod_2)
{
	return (prod_are_equ(prod_1, prod_2));
}

t_bool			sym_are_equ(t_symbol const *sym_1, t_symbol const *sym_2)
{
	return (ft_strequ(sym_1->name, sym_2->name)
			&& lst_equ(sym_1->prods, sym_2->prods, equ));
}