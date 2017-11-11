/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:53:11 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/11 12:32:26 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"
#include "sym_interface.h"
#include "libft.h"
#include <stdarg.h>

static void	print_sym(void const *v_sym, va_list args)
{
	int	fd;

	fd = va_arg(args, int);
	print_sym_back(v_sym, fd);
	ft_putstr_fd(";\n", fd);
}

void	print_grammar_back(int const fd, t_grammar const *gram)
{
	size_t	index;

	index = 0;
	f_fifoiter_va(gram->sym_list, print_sym, fd);
}
