/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 17:26:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/15 12:50:01 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_interface.h"
#include "sym_interface.h"
#include "libft.h"
#include <stdlib.h>

/*
** Test that the parsing of a prod correctly create "pending symbols", which
** shall be defined later, if they are not yet defined in the "added_symbol"
** list
*/

t_bool			test_prod_parse(t_fifo const *sym_added,
		t_fifo *sym_pending)
{
	const char	expect_input[] = "NON_TERM TERM_1 TERM_2 ";
	t_prod		*prod;
	t_bool		result;

	prod = parse_prod(expect_input, sym_added, sym_pending);
	result = (get_prod_len(prod) == 3 && fifo_len(sym_pending) == 2);
	destroy_prod(&prod);
	return (result);
}

int				main(void)
{
	char	*sym_names[] = {"TERM_1" "TERM_24", "TERM_7", NULL};
	t_fifo	*sym_added[2];
	t_bool	result;
	size_t	index;

	sym_added[0] = f_fifo_create();
	sym_added[1] = f_fifo_create();
	index = 0;
	while (sym_names[index] != NULL)
	{
		f_fifo_add(sym_added[0], create_symbol(sym_names[index]));
		index++;
	}
	result = test_prod_parse(sym_added[0], sym_added[0]);
	f_fifo_destroy(&sym_added[0], no_destroy);
	f_fifo_destroy(&sym_added[1], no_destroy);
	return (result ? EXIT_SUCCESS : EXIT_FAILURE);
}
