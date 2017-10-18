/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_interface.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:11:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/17 09:14:00 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAM_GEN_SYM_INTERFACE_H
# define GRAM_GEN_SYM_INTERFACE_H
# include "prods_interface.h"
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

t_prod		*add_prod(t_symbol *sym, t_prod *prod);

/*
** Getters
** Take left recursive remove a t_prod object from sym and returns it, or return
** NULL if there is no left recursive production in the symbol.
** Implementation file : sym_get.c
*/

t_prod		*take_left_recursive(t_symbol *sym);
char const	*get_name(t_symbol const *sym);
size_t		get_prod_nb(t_symbol const *sym);

/*
** Printers
** Implementation file : sym_print.c
*/

void		print_sym_initializer(t_symbol const *sym, int fd);

/*
** Parsing a prod
** Implementation file : sym_parse.c
*/

t_symbol	*parse_symbol(char const *str_sym);

#endif
