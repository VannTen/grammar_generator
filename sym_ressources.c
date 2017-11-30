/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_ressources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 10:16:08 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/30 11:21:19 by mgautier         ###   ########.fr       */
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
		new->name = ft_strdup(name);
		new->prods = NULL;
		if (new->name == NULL)
			destroy_symbol(&new);
	}
	return (new);
}

void		destroy_symbol(t_symbol **to_destroy)
{
	t_symbol	*sym;

	sym = *to_destroy;
	if (sym != NULL)
	{
		ft_strdel((char**)&sym->name);
		f_lstdel(&sym->prods, iter_del_prod);
		free(sym);
		*to_destroy = NULL;
	}
}

t_symbol	*derivate_new_sym(t_symbol const *src,
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
