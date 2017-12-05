/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_interface.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:11:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/05 14:01:09 by mgautier         ###   ########.fr       */
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

t_symbol		*create_symbol(char const *name);
void			destroy_symbol(t_symbol **to_destroy);
t_symbol		*derivate_new_sym(t_symbol const *src,
		char const *reason_why);

/*
** Setters
** Implementation file : sym_set.c
*/

typedef t_prod	*(*t_prod_ft)(t_prod*, va_list);

t_prod			*add_prod(t_symbol *sym, t_prod *prod);

/*
** Getters
** Take left recursive remove a t_prod object from sym and returns it, or return
** NULL if there is no left recursive production in the symbol.
** Implementation file : sym_get.c
*/

t_prod			*take_left_recursive(t_symbol *sym);
t_bool			has_left_recursion(t_symbol const *sym);
char const		*get_name(t_symbol const *sym);
size_t			get_prod_nb(t_symbol const *sym);

/*
** For debug
*/

t_prod const	*get_prod_number(t_symbol const *sym, size_t number);

/*
** Printers
** Implementation file : sym_print.c
*/

void			print_sym_initializer(t_symbol const *sym, int fd);

/*
** Printers debug
** Implementation file : sym_print_back.c
*/

void			print_sym_back(t_symbol const *sym, int fd);

/*
** Parsing one symbol
** Implementation file : sym_parse.c
*/

t_symbol		*parse_symbol(char const *str_sym,
		t_fifo *sym_added,
		t_fifo *sym_pending);

/*
** Eliminate simple left recursion in a symbol.
** Implementation file : sym_transform_lrec.c
*/

t_symbol		*eliminate_left_recursion(t_symbol *sym);

/*
** Tool for eliminating indirect left recursion.
** Suppress reference to previous symbols by expanding them into their
** productions
** Implementation file : sym_transform_indirect_lrec.c
*/


t_bool			elim_indirect_left_recursion(
		t_symbol *sym,
		t_symbol const *sym_indir,
		t_bool dev_if_left);

/*
** Symbols equality (test purposes)
** Implementation file : sym_equality.c
**
** same_sym_parsed() : to be used in higher-order variadic functions.
*/

t_bool			symbol_are_identical(
		t_symbol const *sym,
		t_symbol const *sym_2);
t_bool			same_sym_parsed(const void *v_sym, va_list args);
t_bool			have_same_prods(t_symbol const *sym_1, t_symbol const *sym_2);

/*
** Symbols comparison (to compare different grammars)
** Implementation file : sym_cmp.c
*/

t_bool			sym_are_equ(t_symbol const *sym_1, t_symbol const *sym_2);
t_bool			prods_are_equ(t_symbol const *sym_1, t_symbol const *sym_2);

/*
** Sym valid names
** Implementation file : sym_valid.c
*/

t_bool			is_valid_sym_name_part(char c);
t_bool			is_valid_sym_name(char const *str);

#endif
