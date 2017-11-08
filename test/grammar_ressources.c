/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_ressources.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:05:00 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/08 15:13:56 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_interface.h"
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	t_grammar	*gram;

	if (argc < 1)
	{
		gram = parse_grammar(argv[1]);
		if (gram == NULL)
			return (EXIT_FAILURE);
		destroy_grammar(&gram);
		if (gram != NULL)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
