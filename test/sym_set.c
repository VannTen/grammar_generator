/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:04:35 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/08 17:04:41 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "prods_defs.h"
#include "libft.h"
#include <stdlib.h>

int	main(void)
{
	const char	*symbol[] = {
		"SYMBOL : OTHER_SYMBP OTHER | SYM | SYMI OTHER SYMO",
		"SYMBOL : OTHER_SYMBP OTHER | SYM "};
	const char	prod_str[] = "SYMI OTHER SYMO";
	t_symbol	*symbols[2];
	t_prod		*prod;
	t_bool		result;

	symbols[0] = parse_symbol(symbol[0]);
	symbols[1] = parse_symbol(symbol[1]);
	prod = parse_one_prod(prod_str);
	if (symbols[0] != NULL && symbols[1] != NULL && prod != NULL)
	{
		add_prod(symbols[1], prod);
		result = symbol_are_identical(symbols[0], symbols[1]);
	}
	else
		result = FALSE;
	destroy_symbol(&symbols[0]);
	destroy_symbol(&symbols[1]);
	return (result ? EXIT_SUCCESS : EXIT_FAILURE);
}
