/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_construct_interface.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:54:54 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/23 18:54:54 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_CONSTRUCT_INTERFACE_H
# define EXEC_CONSTRUCT_INTERFACE_H

typedef struct s_exec_construct	t_exec_construct;

/*
** exec stack operation
** Perform operation need on the parser exec_stack to always have the instance
** of the symbol being currently parsed on top of it.
** Implemenation file : parser_exec_stack.c
*/

t_symbol const	*take_one_symbol(t_lst **parse_stack, t_lst **exec_stack);


/*
** Meta construct
**
** The meta construct is to be created at the initialization of the parsing
** automaton. Is it placed at the top of the execute stack, in order to ease the
** piling and depiling. The argument provided to the constructor shall be the
** address where should be stored the return of the 'create' function
** for the execution construct corresping to the 'construct' argument.
**
** Implementation file : exec_stack_meta_construct.c
*/

t_exec_construct	*create_init_meta_construct(void);
void				*extract_top_symbol_value(t_exec_construct **meta);

#endif
