/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_interface.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:43:48 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/10 22:06:34 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_INTERFACE_H
# define TEST_INTERFACE_H
# include "prods_interface.h"
# include "sym_interface.h"
# include "grammar_interface.h"

/*
** Header for test functions used by many test. Having them as part of the
** project avoid to duplicate test code.
*/

/*
** Prod debug get
** Implementation file : prod_get_test.c
*/

t_lst const		*get_prod_lst(t_prod const *prod);

/*
** Test syms and prods interaction (add, remove, ect)
** Implementation file : test_prods_syms.c
*/

t_bool	test_sym_prod(
		char const **str,
		size_t nb_prods,
		size_t nb_symbols,
		t_bool (*test)(t_prod **prod, t_symbol **syms, ...));

/*
** Compute first test tools
** Providing used by several test to test the set of functions of compute_first
** Implementation file : compute_first_test_tools.c
*/

t_lst	*str_to_first_set_lst(char const **array, size_t nb_sym);
void	destroy_cmp_first_set(void **first_set);
void	print_first_set_comp(t_lst const *first_set, int fd);

/*
** Compute sets test tools
** Implementation file : compute_set_test_tools.c
*/

t_bool	check_sets(
		void *set_cmp,
		void *item_array,
		size_t nb_item,
		t_bool (*check)(void const *cmp, void const *item));

/*
** Compute first test tools on sym
** Implementation file : sym_compute_first_test_tools.c
*/

void	print_symbol_first_set(t_symbol const *sym, int const fd);
t_bool	check_first_sets(
		t_symbol **syms, t_lst **first_sets, size_t nb_sym);
t_bool	compute_first_sets(t_symbol **syms, size_t nb_sym);
t_bool	check_first_sets(
		t_symbol **syms, t_lst **first_sets, size_t nb_sym);

/*
** Compute follow test tools on sym
** Implementation file : sym_compute_follow_test_tools.c
*/

t_bool	compute_follow_sets(t_symbol **syms, size_t nb_sym);

/*
** Grammar compute first_tools test
** Implementation file : grammar_compute_first_test_tools.c
*/

void	print_first_sets(t_grammar const *gram, int fd);
void	print_follow_sets(t_grammar const *gram, int fd);

/*
** Grammar compute_follow tools for testing
** Implementation file : grammar_compute_follow_test_tools.c
*/


/*
** Grammar tools for test on first and follow sets
** Implementation file : grammar_compute_set_test_tools.c
*/

t_bool	gram_check_first_sets(
		t_grammar const *gram, t_lst const *first_sets);
t_bool	gram_check_follow_sets(
		t_grammar const *gram, t_lst const *first_sets);

/*
** Sym sets test tools
** Implementation file : sym_set_test_tools.c
*/

t_bool	compute_sets_all_syms(t_fifo *tokens, t_fifo *sym_list);

#endif
