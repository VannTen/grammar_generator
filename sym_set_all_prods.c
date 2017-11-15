/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_set_all_prods.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:42:56 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/15 10:46:36 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "prods_interface.h"
#include <stdarg.h>
#include <stdlib.h>

t_symbol	*append_to_each_prod(t_symbol *add_to, t_symbol const *to_add)
{
	size_t	index;

	index = 0;
	while (add_to->prods[index] != NULL)
	{
		if (!append_to_prod(add_to->prods[index], to_add))
			return (NULL);
		index++;
	}
	return (add_to);
}

t_symbol	*prefix_to_each_prod(t_symbol *add_to, t_symbol const *to_add)
{
	size_t	index;

	index = 0;
	while (add_to->prods[index] != NULL)
	{
		if (!prefix_to_prod(add_to->prods[index], to_add))
			return (NULL);
		index++;
	}
	return (add_to);
}

t_symbol	*to_each_prod(t_symbol *add_to, t_prod_ft map, ...)
{
	size_t	index;
	va_list	args;

	index = 0;
	while (add_to->prods[index] != NULL)
	{
		va_start(args, map);
		if (NULL != map(add_to->prods[index], args))
		{
			va_end(args);
			return (NULL);
		}
		va_end(args);
		index++;
	}
	return (add_to);
}
