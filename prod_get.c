/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 11:22:31 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/12 11:24:00 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"
#include <stddef.h>

size_t	get_prod_len(t_prod const *prod)
{
	size_t	size;

	size = 0;
	while (prod[size] != NULL)
		size++;
	return (size);
}
