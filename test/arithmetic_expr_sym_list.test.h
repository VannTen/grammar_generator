/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic_expr_sym_list.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:10:34 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/08 13:31:14 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARITHMETIC_EXPR_SYM_LIST_H
# define ARITHMETIC_EXPR_SYM_LIST_H

typedef enum	e_symbol_type {
	EXPR,
	TERM,
	FACTOR,
	INTEGER,
	MINUS,
	PLUS,
	MULTIPLY,
	DIVIDE,
	LEFT_PAR,
	RIGHT_PAR,
	NB_SYMBOLS
}				t_symbol_type;

#endif
