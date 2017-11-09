/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:04:35 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/09 15:56:03 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "prods_defs.h"
#include "libft.h"
#include <stdlib.h>

static void		parse_and_delete(const char **strs, t_symbol **syms,
		size_t size, t_bool parse)
{
	size_t	index;

	index = 0;
	if (parse)
	{
		while (index < size && (index == 0 || syms[index - 1] != NULL))
		{
			syms[index] = parse_symbol(strs[index]);
			index++;
		}
	}
	else
	{
		while (index < size)
		{
			destroy_symbol(&syms[index]);
			index++;
		}
	}
}

static t_bool	append_prefix_to_each_prod(void)
{
	const char	*symbol[] = {
		"SYMBOL : OTHER_SYMBP OTHER | SYM | SYMI OTHER SYMO",
		"SYMBOL : OTHER_SYMBP OTHER TEKI | SYM TEKI | SYMI OTHER SYMO TEKI",
		"SYMBOL : TAKO OTHER_SYMBP OTHER TEKI | TAKO SYM TEKI |"
			"TAKO SYMI OTHER SYMO TEKI", "TEKI : OTHER_SYMBP OTHER | SYM ",
		"TAKO : OTHER_SYMBP OTHER | SYM "};
	t_symbol	*sym[ARRAY_LENGTH(symbol)];
	t_bool		result;

	result = TRUE;
	parse_and_delete(symbol, sym, ARRAY_LENGTH(symbol), TRUE);
	append_to_each_prod(sym[0], sym[3]);
	if (!symbol_are_identical(sym[0], sym[1]))
		result = FALSE;
	prefix_to_each_prod(sym[0], sym[4]);
	if (!symbol_are_identical(sym[0], sym[2]))
		result = FALSE;
	parse_and_delete(symbol, sym, ARRAY_LENGTH(symbol), FALSE);
	return (result);
}

int				main(void)
{
	const char	*symbol[] = {
		"SYMBOL : OTHER_SYMBP OTHER | SYM | SYMI OTHER SYMO",
		"SYMBOL : OTHER_SYMBP OTHER | SYM "};
	const char	prod_str[] = "SYMI OTHER SYMO";
	t_symbol	*symbols[2];
	t_prod		*prod;
	t_bool		result;

	symbols[0] = parse_symbol(symbol[0]);
	symbols[1] = parse_symbol(symbol[1]);
	prod = parse_one_prod(prod_str);
	if (symbols[0] != NULL && symbols[1] != NULL && prod != NULL)
	{
		add_prod(symbols[1], prod);
		result = symbol_are_identical(symbols[0], symbols[1]);
	}
	else
		result = FALSE;
	destroy_symbol(&symbols[0]);
	destroy_symbol(&symbols[1]);
	return (result && append_prefix_to_each_prod()
			? EXIT_SUCCESS : EXIT_FAILURE);
}
