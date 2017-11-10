/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:34:55 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/10 16:14:27 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include <stdlib.h>

static t_lst	*take_left_recursive_prods(t_symbol *left_recursive_sym)
{
	t_prod		*left_recursive_prod;
	t_fifo		*prod_list;

	left_recursive_prod = take_left_recursive(left_recursive_sym);
	prod_list = f_fifo_create();
	while (left_recursive_prod != NULL)
	{
		f_fifo_add(prod_list, left_recursive_prod);
		left_recursive_prod = take_left_recursive(left_recursive_sym);
	}
	return (f_fifo_extract(&prod_list));
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

static t_prod	*remove_left_recur(t_prod *prod, va_list args)
{
	remove_symbols_head(prod, 1);
	return (append_to_prod((va_arg(args, t_symbol*))->name, prod));
}

t_symbol		*eliminate_left_recursion(t_symbol *left_recursive_sym)
{
	t_lst		*left_rec_prods;
	t_symbol	*new_sym;
	t_prod		*empty_prod;

	left_rec_prods = take_left_recursive_prods(left_recursive_sym);
	if (left_rec_prods != NULL)
	{
		new_sym = derivate_new_sym(left_recursive_sym, "LEFT_RECUR");
		if (new_sym != NULL)
		{
			append_to_each_prod(left_recursive_sym, new_sym);
			while (left_rec_prods != NULL)
				add_prod(new_sym, f_lstpop(&left_rec_prods));
			to_each_prod(new_sym, remove_left_recur, new_sym);
			empty_prod = parse_one_prod("EMPTY");
			add_prod(new_sym, empty_prod);
		}
	}
	else
		new_sym = NULL;
	return (new_sym);
}
