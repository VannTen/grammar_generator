/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic_expr_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:42:09 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/08 11:08:38 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arithmetic_expr_defs.h"
#include <stdlib.h>

t_symbol	**create_arithmetic_expr_grammar(void)
{
	t_symbol	**grammar;
	size_t		index;
	t_symbol	*(*init_func[])(void) = {create_expr, create_term, create_factor, create_integer, create_minus, create_plus, create_multiply, create_divide, create_left_par, create_right_par, NULL};

	index = 0;
	grammar = malloc(sizeof(t_symbol*) * NB_SYMBOLS);
	while (index < NB_SYMBOLS)
	{
		grammar[index] = init_func[index]();
		index++;
	}
	return (grammar);
}
