/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_interface.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 11:33:25 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/16 17:24:31 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAMMAR_INTERFACE_H
# define GRAMMAR_INTERFACE_H

typedef struct s_grammar	t_grammar;

/*
** Grammar creation from text file
** Implementation file : grammar_parse.c
*/

t_grammar	*parse_grammar(const char *grammar_file);

/*
** Ressources management
** Implementation file : grammar_ressources.c
*/

void		destroy_grammar(t_grammar **to_destroy);
t_grammar	*create_grammar(void);

/*
** Grammar output as header and source file
** Implementation file : grammar_print_*.c
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
** Grammar tranformation : placeholders for future transformation operations on
** grammar object (convert it to LL(1) for example)
** Implementation file : grammar_transform.c
*/

typedef enum	e_gram_type
{
	LL_1,
	NB_GRAM_TYPES
}				t_gram_type;

t_grammar	*convert_to(t_grammar const *grammar, t_gram_type type);

#endif
