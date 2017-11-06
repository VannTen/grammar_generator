/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:47:55 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/06 14:20:43 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"
#include "prods_interface.h"
#include "libft.h"
#include <stdlib.h>

static t_bool	prod_are_identical(t_prod const *prod_1, t_prod const *prod_2)
{
	return (ft_str_arraycmp((char const*const*)prod_1,
				(char const*const*)prod_2) == 0);
}

static t_bool	test_left_recur(t_symbol *sym, t_prod const *recur_prod)
{
	t_prod		*left_recur;
	t_bool		result;

	result = FALSE;
	left_recur = take_left_recursive(sym);
		if (prod_are_identical(left_recur, recur_prod)
				&& take_left_recursive(sym) == NULL)
			result = TRUE;
	destroy_one_prod(&left_recur);
	return (result);
}

static t_bool	test_get_name(t_symbol const *sym, char const *name)
{
	return (ft_strequ(get_name(sym),name));
}

static t_bool	test_get_prod_nb(t_symbol const *sym, size_t nb)
{
	return (get_prod_nb(sym) == nb);
}

int				main(void)
{
	const char	symbol_str[] = "SYMBOL: UUUU JJJJ HH| WER| SYMBOL HUI TRE|FRE";
	const char	str_prod[] = "SYMBOL HUI TRE";
	t_symbol	*symbol;
	t_prod		*left_recur;
	t_bool		result;

	symbol = parse_symbol(symbol_str);
	left_recur = parse_one_prod(str_prod);
	if (symbol != NULL && left_recur != NULL)
		result = test_get_name(symbol, "SYMBOL")
			&& test_get_prod_nb(symbol, 4)
			&& test_left_recur(symbol, left_recur);
	else
		result = FALSE;
	destroy_symbol(&symbol);
	destroy_one_prod(&left_recur);
	return (result ? EXIT_SUCCESS : EXIT_FAILURE);
}
