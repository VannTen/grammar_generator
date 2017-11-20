/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_interface.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:43:48 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/20 11:46:44 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_INTERFACE_H
# define TEST_INTERFACE_H
# include "prods_interface.h"
# include "sym_interface.h"

/*
** Header for test functions used by many test. Having them as part of the
** project avoid to duplicate test code.
*/

/*
** Test syms and prods interaction (add, remove, ect)
** Implementation file : test_prods_syms.c
*/

t_bool	test_sym_prod(
		char const **str,
		size_t nb_prods,
		size_t nb_symbols,
		t_bool (*test)(t_prod **prod, t_symbol **syms));

#endif
