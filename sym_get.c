/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 10:06:36 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/16 12:50:06 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include <stddef.h>

size_t		get_prod_nb(t_symbol const *sym)
{
	return (f_lst_len(sym->prods));
}

static t_bool	left_rec(void const *v_prod, va_list args)
{
	return (is_left_recursive(v_prod, va_arg(args, t_symbol const*)));
}

t_prod		*take_left_recursive(t_symbol *sym)
{
	return (f_lsttakeone_if_va(&sym->prods, left_rec, sym));
}

char const *get_name(t_symbol const *sym)
{
	return (sym->name);
}

t_bool		has_left_recursion(t_symbol const *sym)
{
	return (NULL == f_lst_every_valid_va(sym->prods, FALSE, left_rec, sym));
}
