/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 09:28:16 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/18 18:52:35 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_interface.h"
#include "libft.h"
#include <stdlib.h>
#include "prod_get.c"

int	main(void)
{
	const char	*prod[] = {"NEWLINE", "SYN", NULL};
	const char	*app_result[] = {"NEWLINE", "SYN", "DITCH", NULL};
	const char	*pre_result[] = {"DITCH", "NEWLINE", "SYN", NULL};
	const char	*join_result[] = {"NEWLINE", "SYN", "NEWLINE", "SYN", NULL};
	char const	**result;

	result = (char const**)append_to_prod("DITCH", (t_prod*)prod);
	if (!(ft_str_arr_equ(result, app_result)))
		exit(EXIT_FAILURE);
	free_only_str_array(&result);
	result = (char const**)prefix_to_prod("DITCH", (t_prod*)prod);
	if (!(ft_str_arr_equ(result, pre_result)))
		exit(EXIT_FAILURE);
	free_only_str_array(&result);
	result = (char const**)join_prods((t_prod*)prod, (t_prod*)prod);
	if (!(ft_str_arr_equ(result, join_result)))
		exit(EXIT_FAILURE);
	free_only_str_array(&result);
	return (EXIT_SUCCESS);
}
