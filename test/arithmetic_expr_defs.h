/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic_expr_defs.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:49:58 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/07 11:30:31 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARITHMETIC_EXPR_DEFS_H
# define ARITHMETIC_EXPR_DEFS_H
# include "symbol_defs.h"

t_symbol	*create_expr(void);
t_symbol	*create_term(void);
t_symbol	*create_factor(void);
t_symbol	*create_integer(void);
t_symbol	*create_minus(void);
t_symbol	*create_plus(void);
t_symbol	*create_multiply(void);
t_symbol	*create_divide(void);
t_symbol	*create_left_par(void);
t_symbol	*create_right_par(void);

#endif
