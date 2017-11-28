/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_interface.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 11:33:25 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/28 13:05:05 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAMMAR_INTERFACE_H
# define GRAMMAR_INTERFACE_H
# include "libft.h"
# include "sym_interface.h"

typedef struct s_grammar	t_grammar;

typedef enum	e_grammar_class
{
	LL_1,
	LR_1,
	NB_GRAM_CLASS
}				t_gram_class;

/*
** Grammar creation from text file
** Implementation file : grammar_parse.c
*/

t_grammar	*parse_grammar_fd(int fd);
t_grammar	*parse_grammar_file(char const *grammar_file);
t_grammar	*parse_grammar_string(char const *grammar_string);

/*
** Ressources management
** Implementation file : grammar_ressources.c
*/

void		destroy_grammar(t_grammar **to_destroy);
t_grammar	*create_grammar(void);

/*
** Grammar output as header and source file
** Implementation file : grammar_print_*.c
**
** Deprecated.
*/

void		print_grammar_source(t_grammar const *grammar, int fd_source_file,
		char const *no_use);
void		print_grammar_proto(t_grammar const *grammar, int fd_proto_file,
		char const *name);
void		print_grammar_init(t_grammar const *grammar, int fd_init_file,
		char const *header_name);
void		print_grammar_header(t_grammar const *grammar, int fd_header_file,
		char const *name);
void		print_grammar_names(t_grammar const *grammar,
		int fd_names_file, const char *name);

/*
** Grammar printing (for debug)
** Implementation file : grammar_print.c
*/

void		print_grammar_back(int fd, t_grammar const *gram);

/*
** Test grammar, to see if it satisfy certain properties
** Implementation file : grammar_test.c
*/

t_bool		symbols_are_valid(t_grammar const *gram);
t_bool		is_of_class(t_grammar const *gram, t_gram_class type);

/*
** Grammar comparison
** Implementation file : grammar_cmp.c
*/

t_bool		gram_are_equ(t_grammar const *gram_1, t_grammar const *gram_2);

/*
** Getters
** Implementation file : grammar_get.c
*/

size_t			terminal_sym_count(t_grammar const *gram);
size_t			non_terminal_sym_count(t_grammar const *gram);
t_symbol const	*get_start_symbol(t_grammar const *gram);

/*
** Grammar tranformation : placeholders for future transformation operations on
** grammar object (convert it to LL(1) for example)
** Implementation file : grammar_transform.c
*/

t_grammar	*convert_to(t_grammar const *grammar, t_gram_class type);

#endif
