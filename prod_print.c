/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:20:16 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/11 19:39:30 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"

void	print_prod(t_prod const *prod, int const fd)
{
	size_t	index;

	index = 0;
	while (prod[index] != NULL)
	{
		ft_putstr_fd(prod[index], fd);
		index++;
		if (prod[index] != NULL)
			ft_putstr_fd(" ,", fd);
	}
}
