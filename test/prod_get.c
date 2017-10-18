/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 19:02:01 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/18 19:05:00 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_interface.h"
#include <stdlib.h>

int	main(void)
{
	char const	*prod_1[] = {NULL};
	char const	*prod_2[] = {"GTR", "FEF", NULL};

	if (get_prod_len((t_prod const)prod_1) != 0)
		return (EXIT_FAILURE);
	if (get_prod_len((t_prod const)prod_2) != 2)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
