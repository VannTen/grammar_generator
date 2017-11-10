/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:47:13 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/10 13:39:26 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"
#include "libft.h"
#include <stdlib.h>
#include <stdarg.h>

static char		*sta_strip(char const *str, va_list args)
{
	return (ft_strip(str, va_arg(args, char*)));
}

t_prod			*parse_one_prod(char const *one_str_prod)
{
	char	**each_sym_name;
	t_prod	*one_prod;

	each_sym_name = ft_strsplit(one_str_prod, SYMBOL_NAME_SEP);
	one_prod = (const void **)
		ft_str_array_map_va(
				(char const*const*)each_sym_name,
				sta_strip, " \n\t");
	ft_free_string_array(&each_sym_name);
	return (one_prod);
}

static t_bool	is_valid(char const *prod_str)
{
	size_t	index;
	t_bool	unix_case;

	unix_case = FALSE;
	index = 0;
	while (prod_str[index] != '\0')
	{
		if (is_among(" \n\t", prod_str[index])) ;
		else if (is_unix_constants(prod_str[index])
				|| ft_isdigit(prod_str[index]))
			unix_case = TRUE;
		else
			break ;
		index++;
	}
	return (unix_case && prod_str[index] == '\0');
}

t_prod			**parse_prods(char const *str_prods)
{
	char	**each_prod_str;
	size_t	index;
	t_prod	**prods;

	each_prod_str = ft_strsplit(str_prods, PROD_SEP_SIGN);
	if (each_prod_str == NULL)
		return (NULL);
	ft_strip_invalid(each_prod_str, is_valid);
	index = ft_string_array_count((char const* const*)each_prod_str);
	prods = malloc(sizeof(t_prod*) * (index + 1));
	if (prods != NULL)
	{
		index = 0;
		while (each_prod_str[index] != NULL)
		{
			prods[index] = parse_one_prod(each_prod_str[index]);
			index++;
		}
		prods[index] = NULL;
	}
	ft_free_string_array(&each_prod_str);
	return (prods);
}
