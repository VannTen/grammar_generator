/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:02:22 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/18 18:06:07 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_interface.h"
#include <stdlib.h>

int main(void)
{
	const char	*prod_1[] = {"TEST_1", "TEST_2"};

	if (is_left_recursive("TEST_2", (t_prod const*)prod_1))
		return (EXIT_FAILURE);
	if (!is_left_recursive("TEST_1", (t_prod const*)prod_1))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
