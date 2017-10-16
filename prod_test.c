/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:06:53 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/11 19:19:58 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"
#include "libft.h"

t_bool	is_left_recursive(t_sym_name const *sym_name, t_prod const *prod)
{
	return (ft_strequ(sym_name, prod[0]));
}
