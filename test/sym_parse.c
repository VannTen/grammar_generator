/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 19:05:20 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/19 10:19:10 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "libft.h"
#include <errno.h>
#include <stdlib.h>

static t_prod	**prods(void)
{
	static char		*prod_1[] = {"DEI_TT", NULL};
	static char		*prod_2[] = {"UHDE", "IUHDE", NULL};
	static char		*prod_3[] = {"DESDE", NULL};
	static t_prod	*prods[] = {
		(const void**)prod_1,
		(const void**)prod_2,
		(const void**)prod_3,
		NULL};

	return (prods);
}

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

int				main(void)
{
	const char	symbol[] = "HHHH             \n\t   : DEI_TT | UHDE IUHDE     \t"
		"| DESDE|";
	const char	symbol_error[] = "\t\n\t";
	t_symbol	result;
	t_symbol	*test;
	t_bool		success;

	result.name = "HHHH";
	result.prods = prods();
	test = parse_symbol(symbol_error);
	if (test != NULL)
	{
		destroy_symbol(&test);
		return (EXIT_FAILURE);
	}
	test = parse_symbol(symbol);
	errno = 0;
	if (test != NULL)
		success = symbol_are_identical(&result, test);
	else
		success = (errno == ENOMEM);
	destroy_symbol(&test);
	return (success ? EXIT_SUCCESS : EXIT_FAILURE);
}
