/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prods_interface.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:06:36 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/14 09:36:51 by mgautier         ###   ########.fr       */
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

typedef struct s_prod	t_prod;

/*
** Ressources management
** Implementation file : prod_ressources.c
*/

void	destroy_prod(t_prod	**to_destroy);
t_prod	*create_prod(void);

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
void	remove_symbols_head(t_prod *prod, size_t nb_sym);
void	remove_symbols_tail(t_prod *prod, size_t nb_sym);

/*
** Printing prods
** Implemenation file : prod_print.c
*/

void	print_prod(t_prod const *prod, int fd);
void	print_prod_back(t_prod const *prod, int fd);

/*
** Parsing a prod
** Implementation file : prod_parse.c
*/

t_prod	**parse_prods(char const *str_prod);
t_prod	*parse_one_prod(char const *one_str_prod);

/*
** Equality (test if two prods are the same, useful for test purposes)
** Implementation file : prod_equality.c
*/

t_bool	prod_are_identical(t_prod const *prod_1, t_prod const *prod_2);
t_bool	prods_set_identical(t_prod const **prod_1, t_prod const **prod_2);

#endif
