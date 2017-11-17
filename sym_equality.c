/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_equality.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:58:58 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/17 15:25:49 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "libft.h"

t_bool	symbol_are_identical(t_symbol const *sym_1,
		t_symbol const *sym_2)
{
	return (sym_1 == sym_2);
}

t_bool	same_sym_parsed(const void *v_sym, va_list args)
{
	t_symbol const	*sym;

	sym = v_sym;
	return (ft_strequ(get_name(sym), va_arg(args, char const *)));
}
