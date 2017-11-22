/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_defs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:33:25 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/15 13:23:21 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAM_GEN_SYM_DEFS_H
# define GRAM_GEN_SYM_DEFS_H
# include "sym_interface.h"
# define DERIVATION_SIGN ':'
# define PROD_SEP_SIGN '|'

/*
** prods member is a list of t_prod
*/

struct s_symbol
{
	char const	*name;
	t_lst		*prods;
};

#endif
