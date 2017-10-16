/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_print_source.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:33:54 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/12 17:41:22 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"
#include "sym_interface.h"
#include "libft.h"
#include <stdarg.h>

static void	adapt_print(void const *symbol, va_list args)
{
	print_sym_initializer(symbol, va_arg(args, int));
}

void		print_grammar_source(t_grammar const *grammar, int const file,
		char const *dummy)
{
	(void)dummy;
	ft_dprintf(file,
			"#include \"symbol_defs.h\"\n"
			"#include <stdlib.h>\n");
	f_fifoiter_va(grammar->sym_list, adapt_print, file);
}
