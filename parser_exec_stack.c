/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_exec_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:37:22 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/23 13:37:22 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_construct_defs.h"
#include <assert.h>

void				destroy_construct(t_exec_construct **to_destroy)
{
	t_exec_construct	*construct;

	assert(to_destroy != NULL);
	construct = *to_destroy;
	if (construct != NULL)
	{
		construct->symbol = NULL;
		new_construct->derived_length = 0;
		new_construct->real = NULL;
		free(construct);
		*to_destroy = NULL;
	}
}

t_exec_construct	*create_construct(t_symbol const *sym)
{
	t_exec_construct	*new_construct;

	assert(is_exec_consruct(sym));
	new_construct = malloc(sizeof(*new_construct));
	if (new_construct != NULL)
	{
		new_construct->functions = get_exec_functions(sym);
		new_construct->derived_length = 0;
		new_construct->real = NULL;
		if (new_construct->real == NULL)
			destroy_construct(&new_construct);
	}
	return (new_construct)
}

t_symbol const	*take_one_symbol(t_lst **parse_stack, t_lst **exec_stack)
{
	t_exec_construct	*current_construct;

	current_construct = get_lst_elem(*exec_stack, 0);
	assert(current_construct != NULL);
	current_construct->remaining_symbol--;
}

void			one_less_symbol(t_lst **exec_stack)
{
	t_exec_construct	*current_construct;

	current_construct = get_lst_elem(*exec_stack, 0);
	assert(current_construct != NULL);
	current_construct->remaining_symbol--;
	if (current_construct->remaining_symbols == 0)
	{
		(void)f_lstpop(exec_stack);
		destroy_construct(&current_construct);
	}
}

void			give_symbol(t_lst **exec_stack)
{
}

void			give_token(void const *token_value,
		t_lst **exec_stack,
		t_exec const *functions_token)
{
	t_exec_construct	*parent;
	void				*final_token;

	if (functions_token != NULL)
	{
		final_token = functions_token->create(token_value);
		parent = get_lst_elem(*exec_stack, 0);
		parent->functions->give(parent->real, final_token);
	}
	one_less_symbol(exec_stack);
}
