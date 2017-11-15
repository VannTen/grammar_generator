/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:26:14 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/15 15:12:19 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "prods_interface.h"
#include "libft.h"
#include <stdlib.h>

static char		**strip_input(char const *src)
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

static void		*s_prod_parse(void const *v_prod, va_list args)
{
	return (parse_prod(v_prod, va_arg(args, t_fifo const*),
				va_arg(args, t_fifo*)));
}

static t_lst	*parse_prods(char const *str,
	t_fifo const *sym_added, t_fifo *sym_pending)
{
	t_lst	*each_prod_str;
	t_lst	*each_prod;

	each_prod_str = f_strsplit_lst(str, PROD_SEP_SIGN);
	if (each_prod_str != NULL)
		each_prod = f_lstmap_va(each_prod_str, s_prod_parse, iter_del_prod,
				sym_added, sym_pending);
	else
		each_prod = NULL;
	f_lstdel(&each_prod_str, ft_gen_strdel);
	return (each_prod);
}

t_symbol		*parse_symbol(char const *src,
	t_fifo const *sym_added, t_fifo *sym_pending)
{
	char		**name_and_prods;
	t_symbol	*new_symbol;

	name_and_prods = strip_input(src);
	if (name_and_prods != NULL)
	{
		new_symbol = create_symbol(name_and_prods[0]);
		if (new_symbol != NULL)
			new_symbol->prods = parse_prods(name_and_prods[1],
				sym_added, sym_pending);
		else
			new_symbol->prods = NULL;
	}
	else
		new_symbol = NULL;
	ft_free_string_array(&name_and_prods);
	return (new_symbol);
}
