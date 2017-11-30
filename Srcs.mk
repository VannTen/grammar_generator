# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/19 07:58:53 by mgautier          #+#    #+#              #
#*   Updated: 2017/11/30 11:44:27 by mgautier         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

# Define target and sources

TARGET := grammar_generator

SRC :=\
	prod_ressources.c\
	prod_parse.c\
	prod_test.c\
	prod_print.c\
	prod_set.c\
	prod_set_gen.c\
	prod_get.c\
	prod_transform.c\
	prod_equality.c\
	prod_cmp.c\
	sym_valid.c\
	sym_equality.c\
	sym_parse.c\
	sym_print.c\
	sym_print_back.c\
	sym_set.c\
	sym_get.c\
	sym_cmp.c\
	sym_ressources.c\
	sym_transform.c\
	grammar_parse.c\
	grammar_get.c\
	grammar_test.c\
	grammar_cmp.c\
	grammar_ressources.c\
	grammar_transform.c\
	test_prods_syms.c

#	grammar_print_init.c\
#	grammar_print_proto.c\
#	grammar_print_header.c\
#	grammar_print_source.c\
#	grammar_print_names.c\
	generate_grammar.c\
# Directories

SRC_DIR :=
OBJ_DIR := object
INC_DIR := includes
DEP_DIR := .dep
COMPONENTS :=
LIBRARIES := libft

# Testing

TEST_DIR := test_bin
TEST_SRC_DIR := test
STATIC_TEST_FILES := arithmetic_expr.grammar\
	arithmetic_expr_init.test.c\
	arithmetic_expr_sym_list.test.h\
	arithmetic_expr_names.test.c

## Units tests

DONT_TEST := \
	prod_set_gen.c\
	prod_equality.c\
	sym_equality.c\
	sym_cmp.c\
	prod_cmp.c\
	grammar_print_init.c\
	grammar_print_proto.c\
	grammar_print_header.c\
	grammar_print_source.c\
	grammar_print_names.c\
	grammar_get.c\
	grammar_test.c\
	generate_grammar.c\
	test_prods_syms.c

## Function tests

TEST_LIST :=\
	check_generated_files.sh
