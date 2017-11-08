/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 14:45:25 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/08 14:43:37 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"
#include <stdlib.h>
#include <unistd.h>

#define WRITE_END 1
#define READ_END 0

static t_bool	non_terminal_symbol_works(void)
{
	const char	symbol[] = "HHHH           \n\t   : DEI_TT | UHDE IUHDE     \t"
		"| DESDE";
	t_symbol	*test;
	int			pipes[2];
	int			result;
	const char	expected_result[] =
		"\nstatic t_symbol\t*create_hhhh(void)\n" "{\n"
		"\tt_symbol\t*new;\n\n"
		"\tnew = malloc(sizeof(t_symbol));\n"
		"\tif (new != NULL)\n" "\t{\n"
		"\t\tnew->type = HHHH;\n"
		"\t\tnew->productions = malloc(sizeof(t_symbol_type*) * (3 + 1));\n"
		"\t\tif (new->productions != NULL)\n\t\t{\n"
		"\t\t\tnew->productions[0] = generate_one_production(1, DEI_TT);\n"
		"\t\t\tnew->productions[1] = generate_one_production(2, UHDE, IUHDE);\n"
		"\t\t\tnew->productions[2] = generate_one_production(1, DESDE);\n"
		"\t\t\tnew->productions[3] = NULL;\n\t\t}\n\t\telse\n"
		"\t\t\tdestroy_symbol(&new);\n"
		"\t}\n"
		"\treturn (new);\n" "}\n";

	pipe(pipes);
	test = parse_symbol(symbol);
	print_sym_initializer(test, pipes[WRITE_END]);
	close(pipes[WRITE_END]);
	result = ft_str_fd_cmp(expected_result, pipes[READ_END]);
	close(pipes[READ_END]);
	return (result == 0);
}

static t_bool	terminal_symbol_works(void)
{
	const char	symbol[] = "HHHH";
	t_symbol	*test;
	int			pipes[2];
	int			result;
	const char	expected_result[] =
		"\nstatic t_symbol\t*create_hhhh(void)\n"
		"{\n"
		"\tt_symbol\t*new;\n\n"
		"\tnew = malloc(sizeof(t_symbol));\n"
		"\tif (new != NULL)\n"
		"\t{\n"
		"\t\tnew->type = HHHH;\n"
		"\t\tnew->productions = NULL;\n"
		"\t}\n"
		"\treturn (new);\n"
		"}\n";

	pipe(pipes);
	test = parse_symbol(symbol);
	print_sym_initializer(test, pipes[WRITE_END]);
	close(pipes[WRITE_END]);
	result = ft_str_fd_cmp(expected_result, pipes[READ_END]);
	close(pipes[READ_END]);
	return (result == 0);
}

int				main(void)
{
	if (terminal_symbol_works() && non_terminal_symbol_works())
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
