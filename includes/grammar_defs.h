/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_defs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 12:00:16 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/08 11:16:20 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAMMAR_DEFS_H
# define GRAMMAR_DEFS_H
# include "grammar_interface.h"
# include "libft.h"

/*
** Sym_list is a list of t_symbol element
*/

struct s_grammar
{
	char const	*start_symbol;
	t_fifo		*sym_list;
	char		*name;
};

#endif
