/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_equality.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:48:06 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/08 16:56:34 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_interface.h"
#include "libft.h"

t_bool	prod_are_identical(t_prod const *prod_1, t_prod const *prod_2)
{
	return (ft_str_arraycmp((char const*const*)prod_1,
				(char const*const*)prod_2) == 0);
}

t_bool	prods_set_identical(t_prod const **set_1, t_prod const **set_2)
{
	size_t	index;

	index = 0;

	while (set_2[index] != NULL && set_1[index] != NULL
			&& prod_are_identical(set_1[index], set_2[index]))
		index++;
	if (set_2[index] != NULL || set_1[index] != NULL)
		return (FALSE);
	else
		return (TRUE);
}
