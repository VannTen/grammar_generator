/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:14:53 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/24 12:59:45 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"
#include "libft.h"
#include <assert.h>

size_t			terminal_sym_count(t_grammar const *gram)
{
	assert(gram != NULL);
	return (fifo_len(gram->tokens_list));
}

size_t			non_terminal_sym_count(t_grammar const *gram)
{
	assert(gram != NULL);
	return (fifo_len(gram->sym_list));
}

t_symbol const	*get_start_symbol(t_grammar const *gram)
{
	assert(gram != NULL);
	return (get_fifo_elem(gram->sym_list, 0));
}
