/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_ressources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 11:00:42 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/17 17:26:03 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"
#include <stdlib.h>

static void	destroy_one_prod(t_prod	**to_destroy)
{
	t_prod	*one_prod;
	size_t	index;

	one_prod = *to_destroy;
	if (one_prod != NULL)
	{
		index = 0;
		while (one_prod[index] != NULL)
		{
			one_prod[index] = NULL;
			index++;
		}
		free(one_prod);
		*to_destroy = NULL;
	}
}
void		destroy_prods(t_prod ***prods)
{
	t_prod	**prod_set;
	size_t	index;

	prod_set = *prods;
	if (prod_set != NULL)
	{
		index = 0;
		while (prod_set[index] != NULL)
		{
			destroy_one_prod(&prod_set[index]);
			index++;
		}
		free(prod_set);
		*prods = NULL;
	}
}
