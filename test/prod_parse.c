/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 17:26:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/18 17:59:31 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"
#include "libft.h"
#include <stdlib.h>

static t_bool	prod_are_identical(t_prod const *prod_1, t_prod const *prod_2)
{
	return (ft_str_arraycmp((char const*const*)prod_1,
				(char const*const*)prod_2) == 0);
}

static t_bool	prods_set_identical(t_prod const **set_1, t_prod const **set_2)
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
