/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic_expr_source.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:12:42 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/07 11:30:01 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symbol_defs.h"
#include "arithmetic_expr_sym_list.h"
#include <stdlib.h>

t_symbol	*create_expr(void)
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

t_symbol	*create_term(void)
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

t_symbol	*create_factor(void)
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

t_symbol	*create_integer(void)
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

t_symbol	*create_minus(void)
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

t_symbol	*create_plus(void)
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

t_symbol	*create_multiply(void)
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

t_symbol	*create_divide(void)
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

t_symbol	*create_left_par(void)
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

t_symbol	*create_rigth_par(void)
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
