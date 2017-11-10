/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:32:39 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/09 18:53:31 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"
#include "libft.h"
#include <stdlib.h>

static t_bool	test_eliminate_left_recursion(void)
{
	const char	*sym_str[] = {
		"SYMBOL:SYMBOL SYMBOL_3 | SYMBOL HY | SYMBOL_3 | SYMBOL_4",
		"SYMBOL: SYMBOL_3 SYMBOL_LEFT_RECUR | SYMBOL_4 SYMBOL_LEFT_RECUR",
		"SYMBOL_LEFT_RECUR: SYMBOL_3 SYMBOL_LEFT_RECUR | HY SYMBOL_LEFT_RECUR"
			"|EMPTY"};
	t_symbol	*sym[ARRAY_LENGTH(sym_str) + 1];
	size_t		index;
	t_bool		result;

	index = 0;
	while (index < ARRAY_LENGTH(sym_str))
	{
		sym[index] = parse_symbol(sym_str[index]);
		index++;
	}
	sym[index] = eliminate_left_recursion(sym[0]);
	result = symbol_are_identical(sym[0], sym[1])
		&& symbol_are_identical(sym[2], sym[3]);
	index = 0;
	while (index < ARRAY_LENGTH(sym_str) + 1)
	{
		destroy_symbol(&sym[index]);
		index++;
	}
	return (result);
}

int	main(void)
{
	return (test_eliminate_left_recursion() ? EXIT_SUCCESS : EXIT_FAILURE);
}
