/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:47:56 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/13 14:17:49 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "libft.h"

static void	print_prods(t_prod **prods, int const fd)
{
	size_t	index;

	index = 0;
	while (prods[index] != NULL)
	{
		ft_dprintf(fd, "\t\tnew->productions[%zu]"
				" = generate_one_production(%zu, ",
				index, ft_string_array_count((char const* const*)prods[index]));
		ft_print_string_array_fd(fd, (char const* const*)prods[index], ", ");
		ft_putstr_fd(");\n", fd);
		index++;
	}
}

void		print_sym_initializer(t_symbol const *sym, int const fd)
{
	const char	type_name[]	= "t_symbol";
	char		*lower_case;
	size_t		nb_prod;

	nb_prod = sym->prods == NULL ?
		0 : ft_string_array_count((char const* const*)sym->prods);
	lower_case = ft_strmap(sym->name, f_tolower);
	ft_dprintf(fd, "\n%1$s\t*create_%2$s(void)\n{\n"
			"\t%1$s\t*new;\n"
			"%4$s"
			"\tnew = malloc(sizeof(t_symbol));\n"
			"\tif (new != NULL)\n\t{\n"
			"\t\tnew->type = %3$s;\n", type_name, lower_case, sym->name,
			nb_prod != 0 ? "\tsize_t\t\tindex;\n\n" : "");
	if (nb_prod == 0)
		ft_dprintf(fd, "\t\tnew->productions = NULL;\n");
	else
	{
		ft_dprintf(fd,
				"\t\tnew->productions = malloc(sizeof(t_symbol_type*)"
				" * (%1$zu + 1));\n"
				, nb_prod);
		print_prods(sym->prods, fd);
		ft_dprintf(fd, "\t\tnew->productions[%zu] = NULL;\n", nb_prod);
	}
	ft_strdel(&lower_case);
	ft_dprintf(fd, "\t}\n\treturn (new);\n}\n");
}
