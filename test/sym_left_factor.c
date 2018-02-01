/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_left_factor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:38:39 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/20 17:38:17 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"
#include "test_interface.h"
#include "libft.h"
#include <unistd.h>

static char const	*g_str_symbol[] = {
	"SYM: A B C D E"
		"| A B C"
		"| A B C F E"
		"| A B D W"
		"| A B D"
		"| A B D E"
		"| A B W"
		"|"
		"| A B E",
	"SAM: A B SYM_2_LFAC_ |",
	"SYM_2_LFAC_: E | W | D SYM_0_LFAC_ | C SYM_1_LFAC_",
	"SYM_1_LFAC_: | D E | F E",
	"SYM_0_LFAC_: | E | W"
};

static t_bool		test_left_factor(
		__attribute__((unused))t_prod **prods,
		t_symbol **syms,
		...)
{
	t_fifo	*new_syms;
	t_bool	result;
	size_t	index;

	new_syms = f_fifo_create();
	left_factor_sym(syms[0], new_syms);
	result = prods_are_equ(syms[0], syms[1]);
	result = result && sym_are_equ(syms[2], get_fifo_elem(new_syms, 0));
	result = result && sym_are_equ(syms[3], get_fifo_elem(new_syms, 1));
	index = 0;
	while (!result && index < ARRAY_LENGTH(g_str_symbol))
	{
		print_sym_back(syms[index], STDERR_FILENO);
		ft_dprintf(STDERR_FILENO, "\nSym number %zu\n", index);
		index++;
	}
	index = 0;
	ft_putstr_fd("\n", STDERR_FILENO);
	while (!result && index < fifo_len(new_syms))
	{
		print_sym_back(get_fifo_elem(new_syms, index), STDERR_FILENO);
		ft_dprintf(STDERR_FILENO, "\nSym result number %zu\n", index);
		index++;
	}
	f_fifo_destroy(&new_syms, iter_del_sym);
	return (result);
}

int					main(void)
{
	RET_TEST(test_sym_prod(g_str_symbol, 0, ARRAY_LENGTH(g_str_symbol),
				test_left_factor));
}
