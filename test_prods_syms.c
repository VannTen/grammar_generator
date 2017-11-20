/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_prods_syms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:47:06 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/20 15:21:16 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_interface.h"
#include "prods_interface.h"
#include "sym_interface.h"
#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>

static void		destroy_prods(t_prod ***d_prods, size_t nb_prod)
{
	size_t	index;
	t_prod	**prods;

	prods = *d_prods;
	if (prods != NULL)
	{
		index = 0;
		while (index < nb_prod && prods[index] != NULL)
		{
			destroy_prod(&prods[index]);
			index++;
		}
		free(prods);
		*d_prods = NULL;
	}
}

static void		destroy_symbols(t_symbol ***d_symbols, size_t nb_symbol)
{
	size_t		index;
	t_symbol	**symbols;

	symbols = *d_symbols;
	if (symbols != NULL)
	{
		index = 0;
		while (index < nb_symbol && symbols[index] != NULL)
		{
			destroy_symbol(&symbols[index]);
			index++;
		}
		free(symbols);
		*d_symbols = NULL;
	}
}

static t_prod	**parse_prods(
		char const **str,
		size_t nb_prods,
		t_fifo **sym_lists)
{
	size_t	index;
	t_prod	**prods;

	prods = malloc(sizeof(t_prod*) * nb_prods);
	if (prods != NULL)
	{
		index = 0;
		while (index < nb_prods)
		{
			prods[index] = parse_prod(str[index], sym_lists[0], sym_lists[1]);
			if (prods[index] == NULL)
				break ;
			index++;
		}
		if (index < nb_prods)
			destroy_prods(&prods, nb_prods);
	}
	return (prods);
}

static t_symbol	**parse_symbols(
		char const **str,
		size_t nb_symbols,
		t_fifo **sym_lists)
{
	size_t		index;
	t_symbol	**symbols;

	symbols = malloc(sizeof(t_symbol*) * nb_symbols);
	if (symbols != NULL)
	{
		index = 0;
		while (index < nb_symbols)
		{
			symbols[index] = parse_symbol(
					str[index], sym_lists[0], sym_lists[1]);
			if (symbols[index] == NULL)
				break ;
			index++;
		}
		if (index < nb_symbols)
			destroy_symbols(&symbols, nb_symbols);
	}
	return (symbols);
}

t_bool			test_sym_prod(
		char const **str,
		size_t nb_prods,
		size_t nb_symbols,
		t_bool (*test)(t_prod **prod, t_symbol **syms, ...))
{
	t_prod		**prods;
	t_symbol	**syms;
	t_fifo		*sym_lists[2];
	t_bool		result;

	sym_lists[0] = f_fifo_create();
	sym_lists[1] = f_fifo_create();
	prods = parse_prods(str, nb_prods, sym_lists);
	syms = parse_symbols(str + nb_prods, nb_symbols, sym_lists);
	if (prods != NULL && syms != NULL)
		result = test(prods, syms, sym_lists[0], sym_lists[1],
				nb_prods, nb_symbols);
	else
		result = FALSE;
	destroy_prods(&prods, nb_prods);
	destroy_symbols(&syms, nb_symbols);
	return (result);
}
