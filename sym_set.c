/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 20:03:33 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/10 15:44:23 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "prods_interface.h"
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
		if (sym->prods != NULL)
		{
			while (sym->prods[index] != NULL)
			{
				new_prods[index] = sym->prods[index];
				index++;
			}
		}
		new_prods[index] = prod;
		new_prods[index + 1] = NULL;
		free(sym->prods);
		sym->prods = new_prods;
		return (NULL);
	}
	return (prod);
}
