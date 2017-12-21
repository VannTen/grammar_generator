/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_compute_first_test_tools.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:19:51 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/05 20:34:18 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"
#include "libft.h"
#include <stddef.h>
#include <unistd.h>

static t_bool	equ(void const *str, void const *sym)
{
	return (ft_strequ(str, get_name(sym)));
}

static void		print(void *sym)
{
	ft_dprintf(STDERR_FILENO, "%s\n", get_name(sym));
}

static void		print_comparison(void *str)
{
	ft_dprintf(STDERR_FILENO, "%s\n", str);
}

t_bool	compute_first_sets(
		t_symbol **syms, size_t nb_sym)
{
	size_t	index;
	t_bool	sym_added;
	t_bool	redundant;

	sym_added = TRUE;
	while (sym_added == TRUE)
	{
		index = 0;
		sym_added = FALSE;
		while (index < nb_sym)
		{
			redundant = FALSE;
			compute_sym_first_set(syms[index], &sym_added);
			compute_sym_first_set(syms[index], &redundant);
			if (redundant)
			{
				ft_dprintf(STDERR_FILENO,
						"Two add to first in %s\n", get_name(syms[index]));
				return (FALSE);
			}
			index++;
		}
	}
	return (TRUE);
}

t_bool	check_first_sets(
		t_symbol **syms, t_lst **first_sets, size_t nb_sym)
{
	size_t	index;

	index = 0;
	while (index < nb_sym
			&& lst_same_contents(first_sets[index],
				get_first_set(syms[index]), equ))
		index++;
	if (index != nb_sym)
	{
		ft_dprintf(STDERR_FILENO,
				"expected for symbol %s :\n", get_name(syms[index]));
		f_lstiter(first_sets[index], print_comparison);
		ft_dprintf(STDERR_FILENO, "result :\n");
		f_lstiter((t_lst*)get_first_set(syms[index]), print);
	}
	return (index == nb_sym);
}
