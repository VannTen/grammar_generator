/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:06:53 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/16 12:49:41 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"
#include "libft.h"

t_bool	is_left_recursive(t_prod const *prod, t_symbol const *sym)
{
	return (f_lst_first_elem(prod->sym_list) == sym);
}
