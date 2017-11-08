#include "arithmetic_expr_sym_list.h"
#include <stddef.h>

char const	*get_symbol_name(t_symbol_type symbol)
{
	char const* const	names[] = {"EXPR", "TERM", "FACTOR", "INTEGER", "MINUS", "PLUS", "MULTIPLY", "DIVIDE", "LEFT_PAR", "RIGHT_PAR", NULL};

	return (names[symbol]);
}
