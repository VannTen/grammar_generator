/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:47:55 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/10 11:21:48 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"
#include "prods_interface.h"
#include "libft.h"
#include <stdlib.h>

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

static t_bool	test_has_left_recurs(void)
{
	const char	*symbol_str[2] = {
		"SYMBOL: UUUU JJJJ HH| WER| SYMBOL HUI TRE|FRE",
		"SYMBOL: UUUU JJJ FF | JE SYMBOL | K SYMBOL" };
	t_symbol	*symbol[2];
	t_bool		result;

	symbol[0] = parse_symbol(symbol_str[0]);
	symbol[1] = parse_symbol(symbol_str[1]);
	result = symbol[0] != NULL && has_left_recursion(symbol[0])
		&& symbol[1] != NULL && !has_left_recursion(symbol[1]);
	destroy_symbol(&symbol[0]);
	destroy_symbol(&symbol[1]);
	return (result);

}

static t_bool	test_get_name(t_symbol const *sym, char const *name)
{
	return (ft_strequ(get_name(sym),name));
}

static t_bool	test_get_prod_nb(t_symbol const *sym, size_t nb)
{
	const char	*sym_str = "SYMBOL:";
	t_symbol	*symbol;
	t_bool		result;

	symbol = parse_symbol(sym_str);
	result = (symbol != NULL && get_prod_nb(symbol) == 0);
	return (result && get_prod_nb(sym) == nb);
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
	if (symbol != NULL && left_recur != NULL && has_left_recursion(symbol))
		result = test_get_name(symbol, "SYMBOL")
			&& test_get_prod_nb(symbol, 4)
			&& test_left_recur(symbol, left_recur)
			&& test_has_left_recurs();
	else
		result = FALSE;
	destroy_symbol(&symbol);
	destroy_one_prod(&left_recur);
	return (result ? EXIT_SUCCESS : EXIT_FAILURE);
}
