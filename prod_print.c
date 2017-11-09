/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:20:16 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/09 16:13:57 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"

static void	print_it(t_prod const *prod, int const fd, char const *sep)
{
	size_t	index;

	index = 0;
	while (prod[index] != NULL)
	{
		ft_putstr_fd(prod[index], fd);
		index++;
		if (prod[index] != NULL)
			ft_putstr_fd(sep, fd);
	}
}

void		print_prod(t_prod const *prod, int const fd)
{
	print_it(prod, fd, ", ");
}

void		print_prod_back(t_prod const *prod, int const fd)
{
	print_it(prod, fd, " ");
}
