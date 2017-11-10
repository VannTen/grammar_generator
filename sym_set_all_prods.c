/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_set_all_prods.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:42:56 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/10 15:52:16 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "prods_interface.h"
#include <stdarg.h>
#include <stdlib.h>

t_symbol	*append_to_each_prod(t_symbol *add_to, t_symbol const *to_add)
{
	size_t	index;
	t_prod	*new_prod;

	index = 0;
	new_prod = add_to->prods[index];
	while (add_to->prods[index] != NULL && new_prod != NULL)
	{
		new_prod = append_to_prod(to_add->name, add_to->prods[index]);
		if (new_prod != NULL)
		{
			destroy_one_prod(&add_to->prods[index]);
			add_to->prods[index] = new_prod;
		}
		index++;
	}
	return (add_to->prods[index] == NULL ? NULL : add_to);
}

t_symbol	*prefix_to_each_prod(t_symbol *add_to, t_symbol const *to_add)
{
	size_t	index;
	t_prod	*new_prod;

	index = 0;
	new_prod = add_to->prods[index];
	while (add_to->prods[index] != NULL && new_prod != NULL)
	{
		new_prod = prefix_to_prod(to_add->name, add_to->prods[index]);
		if (new_prod != NULL)
		{
			destroy_one_prod(&add_to->prods[index]);
			add_to->prods[index] = new_prod;
		}
		index++;
	}
	return (add_to->prods[index] == NULL ? NULL : add_to);
}

t_symbol	*to_each_prod(t_symbol *add_to, t_prod_ft map, ...)
{
	size_t	index;
	va_list	args;
	t_prod	*new_prod;

	index = 0;
	while (add_to->prods[index] != NULL)
	{
		va_start(args, map);
		new_prod = map(add_to->prods[index], args);
		va_end(args);
		if (new_prod != NULL)
		{
			destroy_one_prod(&add_to->prods[index]);
			add_to->prods[index] = new_prod;
		}
		else
			break ;
		index++;
	}
	return (add_to->prods[index] == NULL ? NULL : add_to);
}
