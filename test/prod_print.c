/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:07:15 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/18 18:40:10 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	int			my_pipe[2];
	char const	*prod[] = {"TYPE_1", "TYPE_2", NULL};
	char const	result[] = "TYPE_1, TYPE_2";
	char		buf[100];

	pipe(my_pipe);
	print_prod((t_prod*)prod, my_pipe[1]);
	buf[read(my_pipe[0], buf, 50)] = '\0';
	if (ft_strequ(result, buf))
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
