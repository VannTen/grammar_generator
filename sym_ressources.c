/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_ressources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 10:16:08 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/09 13:26:14 by mgautier         ###   ########.fr       */
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
		new->prods = NULL;
		new->first = NULL;
		new->name = ft_strdup(name);
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
		f_lstdel(&sym->first, no_destroy);
		free(sym);
		*to_destroy = NULL;
	}
}

void		iter_del_sym(void **sym)
{
	destroy_symbol((t_symbol**)sym);
}

t_symbol	*derivate_new_sym(t_symbol const *src,
		char const *reason_why)
{
	t_symbol	*new;
	char		*name;

	name = ft_strvajoin(3, src->name, "_", reason_why);
	if (name != NULL)
		new = create_symbol(name);
	else
		new = NULL;
	ft_strdel(&name);
	return (new);
}
