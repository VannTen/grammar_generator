/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 20:03:33 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/09 18:12:24 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "prods_interface.h"
#include <stdarg.h>
#include <stdlib.h>

t_prod		*add_prod(t_symbol *sym, t_prod *prod)
{
	size_t	nb_prods;
	size_t	index;
	t_prod	**new_prods;

	nb_prods = get_prod_nb(sym);
	new_prods = malloc(sizeof(t_prod*) * (nb_prods + 2));
	if (new_prods != NULL)
	{
		index = 0;
		while (sym->prods[index] != NULL)
		{
			new_prods[index] = sym->prods[index];
			index++;
		}
		new_prods[index] = prod;
		new_prods[index + 1] = NULL;
		free(sym->prods);
		sym->prods = new_prods;
		return (NULL);
	}
	return (prod);
}

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

t_symbol	*to_each_prod(t_symbol *add_to, t_prod_ft apply, ...)
{
	size_t	index;
	t_prod	*check;
	va_list	args;

	index = 0;
	check = NULL;

	while (add_to->prods[index] != NULL && check == NULL)
	{
		va_start(args, apply);
		check = apply(add_to->prods[index], args);
		va_end(args);
		index++;
	}
	return (add_to->prods[index] == NULL ? NULL : add_to);
}
