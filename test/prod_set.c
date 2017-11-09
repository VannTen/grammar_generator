/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 09:28:16 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/09 15:46:30 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_interface.h"
#include "libft.h"
#include <stdlib.h>

static t_bool	test_remove_symbols(void)
{
	const char	*prod_str[] = {"HUE JWE KOL POLI", "JWE KOL POLI", "JWE"};
	t_prod		*prods[ARRAY_LENGTH(prod_str)];
	size_t		index;
	t_bool		result;

	index = 0;
	result = TRUE;
	while (index < ARRAY_LENGTH(prod_str))
	{
		prods[index] = parse_one_prod(prod_str[index]);
		index++;
	}
	remove_symbols_head(prods[0], 1);
	if (!prod_are_identical(prods[0], prods[1]))
		result = FALSE;
	remove_symbols_tail(prods[0], 2);
	if (!prod_are_identical(prods[0], prods[2]))
		result = FALSE;
	index = 0;
	while (index < ARRAY_LENGTH(prod_str))
	{
		destroy_one_prod(&prods[index]);
		index++;
	}
	return (result);
}

int				main(void)
{
	const char	*prod[] = {"NEWLINE", "SYN", NULL};
	const char	*app_result[] = {"NEWLINE", "SYN", "DITCH", NULL};
	const char	*pre_result[] = {"DITCH", "NEWLINE", "SYN", NULL};
	const char	*join_result[] = {"NEWLINE", "SYN", "NEWLINE", "SYN", NULL};
	char const	**result;

	result = (char const**)append_to_prod("DITCH", (t_prod*)prod);
	if (!(ft_str_arr_equ(result, app_result)))
		return(EXIT_FAILURE);
	free_only_str_array(&result);
	result = (char const**)prefix_to_prod("DITCH", (t_prod*)prod);
	if (!(ft_str_arr_equ(result, pre_result)))
		return(EXIT_FAILURE);
	free_only_str_array(&result);
	result = (char const**)join_prods((t_prod*)prod, (t_prod*)prod);
	if (!(ft_str_arr_equ(result, join_result)))
		return(EXIT_FAILURE);
	free_only_str_array(&result);
	return (test_remove_symbols() ? EXIT_SUCCESS : EXIT_FAILURE);
}
