/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:34:55 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/16 15:05:51 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include <stdlib.h>
#include <stdarg.h>

static t_lst		*take_left_recursive_prods(t_symbol *left_recursive_sym)
{
	return (f_split_lst_va(
				&left_recursive_sym->prods,
				gen_prod_is_left_recursive,
				left_recursive_sym));
}

static t_symbol		*derivate_new_sym(t_symbol const *src,
		char const *reason_why)
{
	t_symbol	*new;

	new = malloc(sizeof(t_symbol));
	if (new != NULL)
	{
		new->name = ft_strvajoin(3, src->name, "_", reason_why);
		new->prods = NULL;
		if (new->name == NULL)
			destroy_symbol(&new);
	}
	return (new);
}

static t_bool	remove_left_recur(void *prod, va_list args)
{
	remove_symbols_head(prod, 1);
	return (append_to_prod(prod, va_arg(args, t_symbol const*)));
}

t_symbol		*eliminate_left_recursion(t_symbol *left_recursive_sym)
{
	t_lst		*left_rec_prods;
	t_symbol	*new_sym;

	left_rec_prods = take_left_recursive_prods(left_recursive_sym);
	if (left_rec_prods != NULL)
	{
		new_sym = derivate_new_sym(left_recursive_sym, "LEFT_RECUR");
		if (new_sym != NULL)
		{
			append_to_each_prod(left_recursive_sym, new_sym);
			new_sym->prods = left_rec_prods;
			f_lstiterr_va(new_sym->prods, remove_left_recur, new_sym);
			add_prod(new_sym, get_empty_prod());
		}
	}
	else
		new_sym = NULL;
	return (new_sym);
}
