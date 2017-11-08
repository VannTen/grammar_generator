/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic_expr_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:42:09 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/08 11:50:45 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symbol_defs.h"
#include "arithmetic_expr_sym_list.h"
#include <stdlib.h>

static t_symbol	*create_expr(void)
{
	t_symbol	*new;

	new = malloc(sizeof(t_symbol));
	if (new != NULL)
	{
		new->type = EXPR;
		new->productions = malloc(sizeof(t_symbol_type*) * (3 + 1));
		if (new->productions != NULL)
		{
			new->productions[0] = generate_one_production(3, EXPR, PLUS, TERM);
			new->productions[1] = generate_one_production(3, EXPR, MINUS, TERM);
			new->productions[2] = generate_one_production(1, TERM);
			new->productions[3] = NULL;
		}
		else
			destroy_symbol(&new);
	}
	return (new);
}

static t_symbol	*create_term(void)
{
	t_symbol	*new;

	new = malloc(sizeof(t_symbol));
	if (new != NULL)
	{
		new->type = TERM;
		new->productions = malloc(sizeof(t_symbol_type*) * (3 + 1));
		if (new->productions != NULL)
		{
			new->productions[0] = generate_one_production(3, TERM, MULTIPLY, FACTOR);
			new->productions[1] = generate_one_production(3, TERM, DIVIDE, FACTOR);
			new->productions[2] = generate_one_production(1, FACTOR);
			new->productions[3] = NULL;
		}
		else
			destroy_symbol(&new);
	}
	return (new);
}

static t_symbol	*create_factor(void)
{
	t_symbol	*new;

	new = malloc(sizeof(t_symbol));
	if (new != NULL)
	{
		new->type = FACTOR;
		new->productions = malloc(sizeof(t_symbol_type*) * (3 + 1));
		if (new->productions != NULL)
		{
			new->productions[0] = generate_one_production(1, INTEGER);
			new->productions[1] = generate_one_production(3, LEFT_PAR, EXPR, RIGHT_PAR);
			new->productions[2] = generate_one_production(2, MINUS, FACTOR);
			new->productions[3] = NULL;
		}
		else
			destroy_symbol(&new);
	}
	return (new);
}

static t_symbol	*create_integer(void)
{
	t_symbol	*new;

	new = malloc(sizeof(t_symbol));
	if (new != NULL)
	{
		new->type = INTEGER;
		new->productions = NULL;
	}
	return (new);
}

static t_symbol	*create_minus(void)
{
	t_symbol	*new;

	new = malloc(sizeof(t_symbol));
	if (new != NULL)
	{
		new->type = MINUS;
		new->productions = NULL;
	}
	return (new);
}

static t_symbol	*create_plus(void)
{
	t_symbol	*new;

	new = malloc(sizeof(t_symbol));
	if (new != NULL)
	{
		new->type = PLUS;
		new->productions = NULL;
	}
	return (new);
}

static t_symbol	*create_multiply(void)
{
	t_symbol	*new;

	new = malloc(sizeof(t_symbol));
	if (new != NULL)
	{
		new->type = MULTIPLY;
		new->productions = NULL;
	}
	return (new);
}

static t_symbol	*create_divide(void)
{
	t_symbol	*new;

	new = malloc(sizeof(t_symbol));
	if (new != NULL)
	{
		new->type = DIVIDE;
		new->productions = NULL;
	}
	return (new);
}

static t_symbol	*create_left_par(void)
{
	t_symbol	*new;

	new = malloc(sizeof(t_symbol));
	if (new != NULL)
	{
		new->type = LEFT_PAR;
		new->productions = NULL;
	}
	return (new);
}

static t_symbol	*create_right_par(void)
{
	t_symbol	*new;

	new = malloc(sizeof(t_symbol));
	if (new != NULL)
	{
		new->type = RIGHT_PAR;
		new->productions = NULL;
	}
	return (new);
}

t_symbol		**create_arithmetic_expr_grammar(void)
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
