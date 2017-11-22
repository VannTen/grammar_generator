/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_ressources.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 18:23:50 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/16 17:32:15 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"
#include "sym_interface.h"
#include "libft.h"
#include <stdlib.h>

static void	sym_destroy(void **to_destroy)
{
	destroy_symbol((t_symbol**)to_destroy);
}

void		destroy_grammar(t_grammar **to_destroy)
{
	t_grammar	*gram;

	gram = *to_destroy;
	if (gram != NULL)
	{
		gram->start_symbol = NULL;
		f_fifo_destroy(&gram->sym_list, &sym_destroy);
		f_fifo_destroy(&gram->tokens_list, &sym_destroy);
		ft_strdel(&gram->name);
		free(gram);
		*to_destroy = NULL;
	}
}

t_grammar	*create_grammar(char const *grammar_file)
{
	t_grammar	*new_gram;

	new_gram = malloc(sizeof(t_grammar));
	if (new_gram != NULL)
	{
		new_gram->start_symbol = NULL;
		new_gram->sym_list = f_fifo_create();
		new_gram->tokens_list = f_fifo_create();
		new_gram->name = bare_file_name(grammar_file);
		if (new_gram->name == NULL
				|| new_gram->sym_list == NULL
				|| new_gram->tokens_list == NULL)
			destroy_grammar(&new_gram);
	}
	return (new_gram);
}
