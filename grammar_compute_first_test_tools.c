/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_compute_first_test_tools.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:43:43 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/10 22:08:34 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"
#include "sym_interface.h"
#include "test_interface.h"
#include "libft.h"

static t_bool	equ(void const *str, void const *sym)
{
	return (ft_strequ(str, get_name(sym)));
}

static t_bool	compare_first_sets(void const *sym,
		void const *first_sets_list)
{
	return (lst_same_contents(first_sets_list, get_first_set(sym), equ));
}

t_bool	gram_check_first_sets(
		t_grammar const *gram, t_lst const *first_sets)
{
	return (lst_same_contents(
				get_intern_lst(gram->sym_list),
				first_sets,
				compare_first_sets));
}

static void print_sym_first_set(void const *sym, va_list args)
{
	int	fd;

	fd = va_arg(args, int);
	ft_dprintf(fd, "Sym : %s:\n", get_name(sym));
	print_symbol_first_set(sym, fd);
	ft_dprintf(fd, "\n");
}

void	print_first_sets(t_grammar const *gramm, int const fd)
{
	f_fifoiter_va(gramm->sym_list, print_sym_first_set, fd);
}
