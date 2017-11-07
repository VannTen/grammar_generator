/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic_expr_names.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:53:50 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/07 11:46:09 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arithmetic_expr_sym_list.h"
#include <stddef.h>

char const	*get_symbol_name(t_symbol_type symbol)
{
	char const* const	names[] = {"EXPR", "TERM", "FACTOR", "INTEGER", "MINUS", "PLUS", "MULTIPLY", "DIVIDE", NULL};

	return (names[symbol]);
}
