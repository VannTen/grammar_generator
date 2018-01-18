/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_generation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:11:11 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/18 14:11:11 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_interface.h"
#include "test_interface.h"
#include "libft.h"
# define INTEGER 0
# define LEFT_PAR 1
# define RIGHT_PAR 2
# define END_OF_INPUT 3

static char const	grammar[] =
"EXPR: EXPR PLUS TERM | TERM;"
"TERM: TERM MULT FACTOR | FACTOR;"
"FACTOR: INTEGER | LEFT_PAR EXPR RIGHT_PAR;";

int	main(void)
{
	t_parser			*parser;
	char const			*tokens_name[] = {
		"INTEGER",
		"PLUS",
		"MULT",
		NULL
	};
	t_associate	const	sym[] = {
		{.name = "EXPR", .create = create_expr, .give = give_expr},
		{.name = "TERM", .create = create_term, .give = give_term},
		{.name = "FACTOR", .create = create_factor, .give = give_factor},
		{.name = "INTEGER", .create = create_integer, .give = NULL},
		{.name = NULL, .create = NULL, .give = NULL},
	};
	int				*expr_result;
	char			input[] = "1 + 2 * 3 * (4 + 5)";

	expr_result = NULL;
	parser = generate_parser(
			grammar, tokens_name, sym, get_token_index);
	expr_result = execute_construct(parser, "EXPR", &input, get_token);
	ft_printf("%d\n", *expr_result);
}
