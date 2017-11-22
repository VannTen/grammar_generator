/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 11:45:03 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/16 17:36:44 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"
#include "sym_interface.h"
#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

t_grammar			*parse_grammar(const char *grammar_file)
{
	int			gram_fd;
	t_symbol	*symbol;
	char		*sym_description;
	t_grammar	*new_gram;

	gram_fd = open(grammar_file, O_RDONLY);
	new_gram = create_grammar(grammar_file);
	if (gram_fd != -1)
	{
		while (get_next_elem(gram_fd, &sym_description, ';') == ONE_LINE_READ
				&& sym_description[0] != '\0'
				&& new_gram != NULL)
		{
			symbol = parse_symbol(sym_description,
					new_gram->sym_list, new_gram->tokens_list);
			if (symbol != NULL
					|| NULL == f_fifo_add(new_gram->sym_list, symbol))
				destroy_grammar(&new_gram);
			ft_strdel(&sym_description);
		}
		ft_strdel(&sym_description);
	}
	close(gram_fd);
	return (new_gram);
}
