/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_ressources.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 18:23:50 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/12 18:28:20 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"
#include "sym_interface.h"
#include "libft.h"
#include <stdlib.h>

static void	sym_destroy(void **to_destroy)
{
	destroy_symbol((t_symbol**)to_destroy);
}
void	destroy_grammar(t_grammar **to_destroy)
{
	t_grammar	*gram;

	gram = *to_destroy;
	if (gram != NULL)
	{
		gram->start_symbol = NULL;
		f_fifo_destroy(&gram->sym_list, &sym_destroy);
		free(gram);
		*to_destroy = NULL;
	}
}
