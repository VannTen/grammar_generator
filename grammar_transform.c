/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_transform.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:00:23 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/27 15:45:20 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"

t_grammar	*convert_to(t_grammar const *grammar, t_gram_class type)
{
	(void)type;

	return ((t_grammar*)grammar);
}
