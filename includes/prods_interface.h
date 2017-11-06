/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prods_interface.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:06:36 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/06 13:42:47 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAM_GEN_PRODS_INTERFACE_H
# define GRAM_GEN_PRODS_INTERFACE_H
# include "libft.h"
# include <stddef.h>

/*
** A production is one sequence of symbols which can derivate a non-terminal
** symbols
*/

typedef	void const	t_sym_name;
typedef t_sym_name*	t_prod;

/*
** Ressources management
** Implementation file : prod_ressources.c
*/

void	destroy_prods(t_prod ***prods);
void	destroy_one_prod(t_prod	**to_destroy);

/*
** Testing prod
** Implementation file : prod_test.c
*/

t_bool	is_left_recursive(t_sym_name const *sym_name, t_prod const *prod);

/*
** Getters
** Implementation file : prod_get.c
*/

size_t	get_prod_len(t_prod const *prod);

/*
** Setting prod
** Implementation file : prod_set.c
*/

t_prod	*append_to_prod(t_sym_name const *type, t_prod const *prod);
t_prod	*prefix_to_prod(t_sym_name const *type, t_prod const *prod);
t_prod	*join_prods(t_prod const *prod_1, t_prod const *prod_2);

/*
** Printing prods
** Implemenation file : prod_print.c
*/

void	print_prod(t_prod const *prod, int fd);

/*
** Parsing a prod
** Implementation file : prod_parse.c
*/

t_prod	**parse_prods(char const *str_prod);
t_prod	*parse_one_prod(char const *one_str_prod);

#endif
