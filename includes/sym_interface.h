/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_interface.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:11:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/15 15:18:38 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAM_GEN_SYM_INTERFACE_H
# define GRAM_GEN_SYM_INTERFACE_H
# include "prods_interface.h"
# include <stdarg.h>
# include <stddef.h>

typedef struct s_symbol	t_symbol;

/*
** Ressources management
** Implementation file : sym_ressources.c
*/

t_symbol	*create_symbol(char const *name);
void		destroy_symbol(t_symbol **to_destroy);

/*
** Setters
** Implementation file : sym_set.c
*/

typedef t_prod	*(*t_prod_ft)(t_prod*, va_list);

t_prod			*add_prod(t_symbol *sym, t_prod *prod);
t_symbol		*append_to_each_prod(t_symbol *add_to, t_symbol const *to_add);
t_symbol		*prefix_to_each_prod(t_symbol *add_to, t_symbol const *to_add);
t_symbol		*to_each_prod(t_symbol *add_to, t_prod_ft apply, ...);

/*
** Getters
** Take left recursive remove a t_prod object from sym and returns it, or return
** NULL if there is no left recursive production in the symbol.
** Implementation file : sym_get.c
*/

t_prod		*take_left_recursive(t_symbol *sym);
t_bool		has_left_recursion(t_symbol const *sym);
char const	*get_name(t_symbol const *sym);
size_t		get_prod_nb(t_symbol const *sym);

/*
** Printers
** Implementation file : sym_print.c
*/

void		print_sym_initializer(t_symbol const *sym, int fd);
void		print_sym_back(t_symbol const *sym, int fd);

/*
** Parsing one symbol
** Implementation file : sym_parse.c
*/

t_symbol	*parse_symbol(char const *str_sym,
		t_fifo const *sym_added,
		t_fifo *sym_pending);

/*
** Transforming symbol
** Implementation file : sym_transform.c
*/

t_symbol	*eliminate_left_recursion(t_symbol *sym);

/*
** Symbols equality (test purposes)
** Implementation file : sym_equality.c
*/

t_bool		symbol_are_identical(t_symbol const *sym, t_symbol const *sym_2);

#endif
