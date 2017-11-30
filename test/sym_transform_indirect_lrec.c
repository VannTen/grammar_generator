/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_transform_indirect_lrec.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:09:54 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/30 16:14:07 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"
#include "prods_interface.h"
#include "test_interface.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static t_bool	test_indirect_left_recur(
		__attribute__((unused))t_prod **prods,
		t_symbol **syms,
		...)
{
	t_bool	result;

	elim_indirect_left_recursion(syms[2], syms[1], TRUE);
	result = have_same_prods(syms[2], syms[3]);
	elim_indirect_left_recursion(syms[4], syms[1], TRUE);
	result = have_same_prods(syms[4], syms[5]);
	if (!result)
	{
		print_sym_back(syms[2], STDERR_FILENO);
		ft_putchar_fd(STDERR_FILENO, '\n');
		print_sym_back(syms[3], STDERR_FILENO);
	}
	return (result);

}

int				main(void)
{
	const char	*sym_str[] = {
		"SYM:SYM SYM_4 | SYM HY | SYM_3 | SYM_4",
		"A: AA B C | E R T | F G H",
		"ZZ: A WW | RR E | A FF",
		"ZZ_2: RR E"
			"| AA B C WW | E R T WW | F G H WW"
			"| AA B C FF | E R T FF | F G H FF",
		"FG: EW A | ET | D",
		"FG_2: EW A | ET | D"
	};

	RET_TEST (test_sym_prod(
				sym_str,
				0,
				ARRAY_LENGTH(sym_str),
				test_indirect_left_recur));
}
