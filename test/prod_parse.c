/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 17:26:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/08 16:56:55 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_interface.h"
#include "libft.h"
#include <stdlib.h>

int				main(void)
{
	const char		expect_input[] = "NON_TERM TERM_1 TERM_2   |   "
		"NON_TERM NON_TERM_2";
	char const		*prod_1[] = {"NON_TERM", "TERM_1",
		"TERM_2", NULL};
	char const		*prod_2[] = {"NON_TERM", "NON_TERM_2", NULL};
	t_prod const	*expect_output[] = {(const void**)prod_1,
		(const void**)prod_2, NULL};
	t_prod const	**prods;

	prods = (t_prod const**)parse_prods(expect_input);
	if (prods_set_identical(prods, expect_output))
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
