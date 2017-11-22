/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:07:15 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/17 15:40:07 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_interface.h"
#include "sym_interface.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static void	sym_del(void **content)
{
	destroy_symbol((t_symbol**)content);
}

int main(void)
{
	int			my_pipe[2];
	char const	*prod_str[] = {"TYPE_1 TYPE_2", "TYPE_1, TYPE_2"};
	char		buf[100];
	t_fifo		*fifo[2];
	t_prod		*prod;

	fifo[0] = f_fifo_create();
	fifo[1] = f_fifo_create();
	prod = parse_prod(prod_str[0], fifo[0], fifo[1]);
	pipe(my_pipe);
	print_prod(prod, my_pipe[1]);
	buf[read(my_pipe[0], buf, 50)] = '\0';
	f_fifo_destroy(&fifo[0], sym_del);
	f_fifo_destroy(&fifo[1], sym_del);
	close(my_pipe[0]);
	close(my_pipe[1]);
	if (ft_strequ(prod_str[1], buf))
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
