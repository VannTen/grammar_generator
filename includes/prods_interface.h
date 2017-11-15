/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prods_interface.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:06:36 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/15 11:47:15 by mgautier         ###   ########.fr       */
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

typedef struct s_symbol	t_symbol;

/*
** Some prods functions take a symbol as and address, so I have to include that
** forward declaration to make it compile. That does not grant access to the
** internals of sym.
** However, I wonder if there could be a better way...
** TODO: Search for another way.
*/

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

t_bool	is_left_recursive(t_symbol const *sym, t_prod const *prod);

/*
** Getters
** Implementation file : prod_get.c
*/

size_t	get_prod_len(t_prod const *prod);

/*
** Setting prod
** Implementation file : prod_set.c
*/

t_bool	append_to_prod(t_prod *prod, t_symbol const *type);
t_bool	prefix_to_prod(t_prod *prod, t_symbol const *type);
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

t_prod	*parse_prod(char const *one_str_prod,
		t_fifo const *sym_parsed,
		t_fifo *sym_pending);

/*
** Equality (test if two prods are the same, useful for test purposes)
** Implementation file : prod_equality.c
*/

t_bool	prod_are_identical(t_prod const *prod_1, t_prod const *prod_2);
t_bool	prods_set_identical(t_prod const **prod_1, t_prod const **prod_2);

#endif
