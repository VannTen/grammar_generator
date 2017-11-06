/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 10:06:36 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/06 14:24:48 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include <stddef.h>

size_t		get_prod_nb(t_symbol const *sym)
{
	size_t	size;

	size = 0;
	while (sym->prods[size] != NULL)
		size++;
	return (size);
}

t_prod		*take_left_recursive(t_symbol *sym)
{
	size_t	index;
	t_prod	*prod;

	index = 0;
	prod = NULL;
	while (sym->prods[index] != NULL)
	{
		if (is_left_recursive(sym->name, sym->prods[index]))
		{
			prod = sym->prods[index];
			while (sym->prods[index] != NULL)
			{
				sym->prods[index] = sym->prods[index + 1];
				index++;
			}
			break ;
		}
		index++;
	}
	return (prod);
}

char const *get_name(t_symbol const *sym)
{
	return (sym->name);
}
