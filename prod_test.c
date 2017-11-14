/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:06:53 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/14 10:00:28 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"
#include "libft.h"

static t_bool	test(const void *v_sym, va_list args)
{
	return (v_sym == va_arg(args, t_symbol*));
}

t_bool	is_left_recursive(t_symbol const *sym, t_prod const *prod)
{
	return (NULL == f_lst_every_valid_va(prod->sym_list, test, sym));
}
