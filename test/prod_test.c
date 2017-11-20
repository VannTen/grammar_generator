/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:02:22 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/17 09:17:03 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_interface.h"
#include "sym_interface.h"
#include "libft.h"
#include <stdlib.h>

static t_bool	test(t_symbol **syms, t_prod **prods)
{
	size_t	index[2];

	index[0] = 0;
	while (index[0] < 3)
	{
		index[1] = 0;
		while (index[1] < 3)
		{
			if (!((is_left_recursive(prods[index[1]], syms[index[0]])
					&& index[1] == index[0])
					|| (index[1] != index[0]
					&& !is_left_recursive(prods[index[1]], syms[index[0]]))))
				return (FALSE);
			index[1]++;
		}
		index[0]++;
	}
	return (TRUE);
}

static t_bool	int_test(char **strings)
{
	t_bool		result;
	t_fifo		*sym_list[2];
	t_prod		*prod[3];
	t_symbol	*sym[3];
	size_t		index;

	sym_list[0] = f_fifo_create();
	sym_list[1] = f_fifo_create();
	index = 0;
	while (index < 3)
	{
		sym[index] = parse_symbol(strings[index + 3], sym_list[0], sym_list[1]);
		prod[index] = parse_prod(strings[index], sym_list[0], sym_list[1]);
		index++;
	}
	result = test(sym, prod);
	index = 0;
	while (index < 3)
	{
		destroy_prod(&prod[index]);
		destroy_symbol(&sym[index]);
		index++;
	}
	return (result);
}

int main(void)
{
	char	*str_prod[] = {
		"NON_TERM TERM_1 TERM_2",
		"TERM_1 TERM_2 NON_TERM",
		"TERM_2 NON_TERM TERM_1" ,"NON_TERM", "TERM_1", "TERM_2" };

	return (int_test(str_prod) ? EXIT_SUCCESS : EXIT_FAILURE);
}
