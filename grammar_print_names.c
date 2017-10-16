/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_print_names.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:23:00 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/13 14:12:17 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"
#include "sym_interface.h"

static void	print_symbol_names(t_symbol const *symbol,
		int const file)
{
	ft_dprintf(file, "\"%s\", ", get_name(symbol));
}

static void	adapt_print(void const *symbol, va_list args)
{
	print_symbol_names(symbol, va_arg(args, int));
}

void		print_grammar_names(t_grammar const *grammar, int const file,
		char const *header_name)
{
	ft_dprintf(file,
			"#include \"%s\"\n"
			"char const\t*get_symbol_name(t_symbol_type symbol)\n{\n"
			"\tchar const\t*names_func[] = {", get_no_dir_part(header_name));
	f_fifoiter_va(grammar->sym_list, adapt_print, file);
	ft_dprintf(file, "NULL};\n\n"
			"\treturn (names[symbol]);\n}\n");
}
