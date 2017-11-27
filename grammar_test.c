/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:09:14 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/27 15:55:44 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"
#include "sym_interface.h"
#include "libft.h"
#include <stdarg.h>
#include <stddef.h>
#include <assert.h>

static t_bool	is_terminal(void const *sym,
		__attribute__((unused))va_list args)
{
	assert(sym != NULL);
	return (get_prod_nb(sym) == 0);
}

t_bool	symbols_are_valid(t_grammar const *gram)
{
	assert(gram != NULL);
	return (NULL == f_fifo_every_valid_va(gram->sym_list, FALSE, is_terminal)
			&& NULL == f_fifo_every_valid_va(
				gram->tokens_list, TRUE, is_terminal));
}
