/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_generation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:09:11 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/22 13:09:11 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_defs.h"
#include "test_interface.h"
#include <unistd.h>

static char const	grammar[] =
"EXPR: EXPR PLUS TERM | TERM;"
"TERM: TERM MULT FACTOR | FACTOR;"
"FACTOR: INTEGER | LEFT_PAR EXPR RIGHT_PAR;";

t_bool		test(t_parser const *parser)
{
	t_bool			result[] = {TRUE, FALSE, TRUE, FALSE, FALSE, TRUE};
	char 			*input[] = {
		"1 + 2 * 3 * (4 + 5)", "1 1 +", "1 + 3 + 4 * 4", "*", "4 * * 4",
	"(((4 + 1) + 1) + 1 * 4)"};
	size_t	index;
	void	*ret;
	char	*input_copy;

	index = 0;
	while (index < ARRAY_LENGTH(result))
	{
		input_copy = input[index];
		ret = execute_construct(parser, "EXPR", &input_copy, get_token);
		if (result[index] != (ret != NULL))
		{
			ft_dprintf(STDERR_FILENO, "\"%s\" should %s have syntax error\n",
					input[index], result[index] ? "not" : "");
			break ;
		}
		free(ret);
		index++;
	}
	return (index == ARRAY_LENGTH(result));
}

int	main(void)
{
	t_parser			*parser;
	char const			*tokens_name[] = {
		"INTEGER",
		"PLUS",
		"MULT",
		"LEFT_PAR",
		"RIGHT_PAR",
		NULL
	};
	t_exec	const		sym[] = {
		{.name = "EXPR", .create = create_expr, .give = give_expr},
		{.name = NULL, .create = NULL, .give = NULL},
	};
	t_bool				result;

	parser = generate_parser(
			grammar, tokens_name, sym, get_token_index);
	result = parser == NULL ? FALSE : test(parser);
	if (!result)
		print_grammar_back(2, parser->grammar);
	destroy_parser(&parser);
	RET_TEST(result);
}
