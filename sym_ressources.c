/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_ressources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 10:16:08 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/12 11:07:46 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "prods_interface.h"
#include <stdlib.h>

t_symbol	*create_symbol(char const *name)
{
	t_symbol	*new;
	new = malloc(sizeof(t_symbol));
	if (new != NULL)
	{
		new->name = name;
		new->prods = NULL;
	}
	return (new);
}

void		destroy_symbol(t_symbol **to_destroy)
{
	t_symbol	*sym;

	sym = *to_destroy;
	if (sym != NULL)
	{
		sym->name = NULL;
		destroy_prods(&sym->prods);
		free(sym);
		*to_destroy = NULL;
	}
}
