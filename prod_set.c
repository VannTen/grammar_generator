/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 20:15:17 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/09 13:24:28 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"
#include <stdlib.h>

t_prod	*append_to_prod(t_sym_name *type, t_prod const *prod)
{
	size_t	size;
	size_t	index;
	t_prod	*new_prod;

	size = get_prod_len(prod);
	new_prod = malloc(sizeof (t_intern_sym_name) * (size + 2));
	if (new_prod != NULL)
	{
		index = 0;
		while (prod[index] != NULL)
		{
			new_prod[index] = prod[index];
			index++;
		}
		new_prod[index] = type;
		new_prod[index + 1] = NULL;
	}
	return (new_prod);
}

t_prod	*prefix_to_prod(t_sym_name const *type, t_prod const *prod)
{
	size_t	size;
	size_t	index;
	t_prod	*new_prod;

	size = get_prod_len(prod);
	new_prod = malloc(sizeof (t_intern_sym_name) * (size + 2));
	if (new_prod != NULL)
	{
		index = 0;
		new_prod[index] = type;
		index++;
		while (prod[index - 1] != NULL)
		{
			new_prod[index] = prod[index - 1];
			index++;
		}
		new_prod[index] = NULL;
	}
	return (new_prod);
}

t_prod	*join_prods(t_prod const *prod_1, t_prod const *prod_2)
{
	size_t	size;
	size_t	index_1;
	size_t	index_2;
	t_prod	*result_prod;

	size = get_prod_len(prod_1) + get_prod_len(prod_2);
	result_prod = malloc(sizeof(t_intern_sym_name) * (size + 1));
	if (result_prod != NULL)
	{
		index_1 = 0;
		index_2 = 0;
		while (prod_1[index_1] != NULL)
		{
			result_prod[index_1] = prod_1[index_1];
			index_1++;
		}
		while (prod_2[index_2] != NULL)
		{
			result_prod[index_1 + index_2] = prod_2[index_2];
			index_2++;
		}
		result_prod[index_1 + index_2] = NULL;
	}
	return (result_prod);
}

void	remove_symbols_tail(t_prod *prod, size_t nb_sym)
{
	size_t	index;

	index = 0;
	while (prod[index + nb_sym] != NULL)
		index++;
	while (prod[index] != NULL)
	{
		prod[index] = NULL;
		index++;
	}
}

void	remove_symbols_head(t_prod *prod, size_t nb_sym)
{
	size_t	index;
	size_t	index_back;

	index = 0;
	index_back = 0;
	while (index < nb_sym)
	{
		prod[index] = NULL;
		index++;
	}
	while (prod[index] != NULL)
	{
		prod[index_back] = prod[index];
		prod[index] = NULL;
		index_back++;
		index++;
	}
}
