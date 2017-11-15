/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:47:13 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/15 11:46:55 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"
#include "sym_interface.h"
#include "libft.h"
#include <stdlib.h>
#include <stdarg.h>

static t_bool		not_same_sym(const void *v_sym, va_list args)
{
	t_symbol const	*sym;

	sym = v_sym;
	return (!ft_strequ(get_name(sym), va_arg(args, char const *)));
}

static t_symbol		*find_sym(
		t_fifo const *sym_already_parsed,
		t_fifo *sym_pending,
		char const *sym_name)
{
	t_symbol	*sym_to_add;

	sym_to_add = f_fifo_every_valid_va(
			sym_already_parsed, not_same_sym, sym_name);
	sym_to_add = sym_to_add != NULL ?
		sym_to_add : f_fifo_every_valid_va(sym_pending, not_same_sym, sym_name);
	if (sym_to_add == NULL)
		sym_to_add = create_symbol(sym_name);
	if (sym_to_add != NULL)
		f_fifo_add(sym_pending, sym_to_add);
	return (sym_to_add);
}

static t_bool		is_valid(char const *prod_str)
{
	size_t	index;
	t_bool	unix_case;

	unix_case = FALSE;
	index = 0;
	while (prod_str[index] != '\0')
	{
		if (is_among(" \n\t", prod_str[index])) ;
		else if (is_unix_constants(prod_str[index])
				|| ft_isdigit(prod_str[index]))
			unix_case = TRUE;
		else
			break ;
		index++;
	}
	return (unix_case && prod_str[index] == '\0');
}

static void			error_funct(t_symbol **sym, t_prod **prod, char **syms_name,
		size_t *index)
{
	destroy_symbol(sym);
	destroy_prod(prod);
	while (syms_name[*index] != NULL)
	{
		ft_strdel(&syms_name[*index]);
		(*index)++;
	}
	free(syms_name);
}

t_prod				*parse_prod(
		char const *one_str_prod,
		t_fifo const *sym_parsed,
		t_fifo *sym_pending)
{
	char		**each_sym_name;
	size_t		index;
	t_symbol	*sym_added;
	t_prod		*new_prod;

	index = 0;
	if (!is_valid(one_str_prod))
		return (NULL);
	each_sym_name = ft_strsplit_and(one_str_prod, SYMBOL_NAME_SEP,
			ft_va_strstrip, " \t\n");
	while (each_sym_name[index] != NULL)
	{
		sym_added = find_sym(sym_parsed, sym_pending, each_sym_name[index]);
		if (sym_added == NULL || !append_to_prod(new_prod, sym_added))
			error_funct(&sym_added, &new_prod, each_sym_name, &index);
		index++;
	}
	return (new_prod);
}
