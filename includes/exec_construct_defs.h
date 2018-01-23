/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_construct_defs.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:55:39 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/23 18:55:39 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_CONSTRUCT_DEFS_H
# define EXEC_CONSTRUCT_DEFS_H
# include "exec_construct_interface.h"
# include "exec_interface.h"

struct	s_exec_construct
{
	t_exec const	*functions;
	void			*real;
	size_t			remaining_symbols;
};

#endif
