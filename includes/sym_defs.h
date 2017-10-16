/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_defs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:33:25 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/12 10:54:40 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAM_GEN_SYM_DEFS_H
# define GRAM_GEN_SYM_DEFS_H
# include "sym_interface.h"
# include "prods_interface.h"
# define DERIVATION_SIGN ':'

struct s_symbol
{
	char const	*name;
	t_prod		**prods;
};

#endif
