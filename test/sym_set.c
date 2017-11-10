/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:04:35 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/10 15:48:15 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "prods_defs.h"
#include "libft.h"
#include <stdlib.h>

static t_bool	test_add_prod(t_symbol **syms, t_prod **prod)
{
	const char	*other_sym = " SYMBOL : SYMI OTHER SYMO | SYMI OTHER SYMO";
	t_symbol	*other_symbol;
	t_bool		result;

	other_symbol = parse_symbol(other_sym);
	if (other_symbol != NULL)
	{
		add_prod(syms[1], prod[0]);
		result = symbol_are_identical(syms[0], syms[1]);
		add_prod(syms[2], prod[1]);
		add_prod(syms[2], prod[2]);
		result = result && symbol_are_identical(syms[2], other_symbol);
		destroy_symbol(&other_symbol);
	}
	else
		result = FALSE;
	return (result);
}

static t_bool	test_add_to_no_prod_sym(void)
{
	const char	*srcs[] = {
		"SYMBOL:",
		"PROD SYMBOL EXAMPLE",
		"PROD EXAMPLE SYMBOL ",
		"SYMBOL: PROD SYMBOL EXAMPLE",
		"SYMBOL: PROD SYMBOL EXAMPLE | PROD EXAMPLE SYMBOL" };
	t_symbol	*symbol[3];
	t_prod		*prod[2];
	t_bool		result;

	symbol[0] = parse_symbol(srcs[0]);
	prod[0] = parse_one_prod(srcs[1]);
	prod[1] = parse_one_prod(srcs[2]);
	symbol[1] = parse_symbol(srcs[3]);
	symbol[2] = parse_symbol(srcs[4]);
	add_prod(symbol[0], prod[0]);
	result = symbol_are_identical(symbol[0], symbol[1]);
	add_prod(symbol[0], prod[1]);
	result = result && symbol_are_identical(symbol[0], symbol[2]);
	destroy_symbol(&symbol[0]);
	destroy_symbol(&symbol[1]);
	destroy_symbol(&symbol[2]);
	return (result);
}

int				main(void)
{
	const char	*symbol[] = {
		"SYMBOL : OTHER_SYMBP OTHER | SYM | SYMI OTHER SYMO",
		"SYMBOL : OTHER_SYMBP OTHER | SYM ",
		"SYMBOL : "};
	const char	prod_str[] = "SYMI OTHER SYMO";
	t_symbol	*symbols[ARRAY_LENGTH(symbol)];
	t_prod		*prod[3];
	t_bool		result;

	symbols[0] = parse_symbol(symbol[0]);
	symbols[1] = parse_symbol(symbol[1]);
	symbols[2] = parse_symbol(symbol[2]);
	prod[0] = parse_one_prod(prod_str);
	prod[1] = parse_one_prod(prod_str);
	prod[2] = parse_one_prod(prod_str);
	if (symbols[0] != NULL && symbols[1] != NULL && symbols[2] != NULL
			&& prod[0] != NULL && prod[1] != NULL)
		result = test_add_prod(symbols, prod);
	else
		result = FALSE;
	destroy_symbol(&symbols[0]);
	destroy_symbol(&symbols[1]);
	destroy_symbol(&symbols[2]);
	return (result && test_add_to_no_prod_sym()
			? EXIT_SUCCESS : EXIT_FAILURE);
}
