/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:04:35 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/06 13:44:34 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "prods_defs.h"
#include "libft.h"
#include <stdlib.h>

static t_bool	prod_are_identical(t_prod const *prod_1, t_prod const *prod_2)
{
	return (ft_str_arraycmp((char const*const*)prod_1,
				(char const*const*)prod_2) == 0);
}

static t_bool	prods_set_identical(t_prod **set_1, t_prod **set_2)
{
	size_t	index;

	index = 0;

	while (set_2[index] != NULL && set_1[index] != NULL
			&& prod_are_identical(set_1[index], set_2[index]))
		index++;
	if (set_2[index] != NULL || set_1[index] != NULL)
		return (FALSE);
	else
		return (TRUE);
}

static t_bool	symbol_are_identical(t_symbol const *sym_1,
		t_symbol const *sym_2)
{
	return (ft_strequ(sym_1->name, sym_2->name)
			&& prods_set_identical(sym_1->prods, sym_2->prods));
}

int	main(void)
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
	return (result ? EXIT_SUCCESS : EXIT_FAILURE);
}
