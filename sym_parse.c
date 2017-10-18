/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:26:14 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/18 15:37:52 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"

static char	**strip_input(char const *src)
{
	char	**stripped_input;
	char	*name;
	char	*sym_src;

	sym_src	= ft_strip(src, "\t\n");
	stripped_input = ft_strsplit(sym_src, DERIVATION_SIGN);
	if (stripped_input != NULL && sym_src != NULL)
	{
		name = ft_strip(stripped_input[0], " ");
		if (name != NULL)
		{
			ft_strdel(&stripped_input[0]);
			stripped_input[0] = name;
			name = NULL;
		}
		else
			ft_free_string_array(&stripped_input);
		ft_strdel(&name);
	}
	else
		ft_free_string_array(&stripped_input);
	ft_strdel(&sym_src);
	return (stripped_input);
}

t_symbol	*parse_symbol(char const *src)
{
	char		**name_and_prods;
	t_symbol	*new_symbol;

	name_and_prods = strip_input(src);
	if (name_and_prods != NULL)
	{
		new_symbol = create_symbol(name_and_prods[0]);
		if (new_symbol != NULL)
			new_symbol->prods = parse_prods(name_and_prods[1]);
		else
			new_symbol->prods = NULL;
	}
	else
		new_symbol = NULL;
	ft_free_string_array(&name_and_prods);
	return (new_symbol);
}
