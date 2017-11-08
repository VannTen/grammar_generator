/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 11:45:03 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/08 11:17:07 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"
#include "sym_interface.h"
#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static void			sym_destroy(void **v_sym)
{
	destroy_symbol((t_symbol**)v_sym);
}

static t_grammar	*create_grammar(t_fifo *sym_list, const char *grammar_file)
{
	t_grammar	*new_gram;

	new_gram = malloc(sizeof(t_grammar));
	if (new_gram != NULL)
	{
		new_gram->start_symbol = get_name(f_fifo_first_elem(sym_list));
		new_gram->sym_list = sym_list;
		new_gram->name = bare_file_name(grammar_file);
		if (new_gram->name == NULL)
			destroy_grammar(&new_gram);
	}
	return (new_gram);
}

t_grammar			*parse_grammar(const char *grammar_file)
{
	int			gram_fd;
	t_symbol	*symbol;
	char		*sym_description;
	t_fifo		*sym_list;
	t_grammar	*new_gram;

	gram_fd = open(grammar_file, O_RDONLY);
	sym_list = f_fifo_create();
	new_gram = NULL;
	if (gram_fd != -1 && sym_list != NULL)
	{
		while (get_next_elem(gram_fd, &sym_description, ';') == ONE_LINE_READ
				&& sym_description[0] != '\0')
		{
			symbol = parse_symbol(sym_description);
			if (symbol != NULL)
				f_fifo_add(sym_list, symbol) == NULL ? fatal(): NULL_EXPR;
			ft_strdel(&sym_description);
		}
		new_gram = create_grammar(sym_list, grammar_file);
		if (new_gram == NULL)
			f_fifo_destroy(&sym_list, sym_destroy);
	}
	close(gram_fd);
	return (new_gram);
}
