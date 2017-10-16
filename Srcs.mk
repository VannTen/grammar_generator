# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/19 07:58:53 by mgautier          #+#    #+#              #
#*   Updated: 2017/10/16 16:27:47 by mgautier         ###   ########.fr       *#
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
	prod_get.c\
	sym_parse.c\
	sym_print.c\
	sym_set.c\
	sym_get.c\
	sym_ressources.c\
	grammar_parse.c\
	grammar_print_init.c\
	grammar_print_proto.c\
	grammar_print_header.c\
	grammar_print_source.c\
	grammar_print_names.c\
	grammar_ressources.c\
	grammar_transform.c\
	generate_grammar.c

# Directories

SRC_DIR :=
OBJ_DIR := object
INC_DIR := includes
DEP_DIR := .dep
TEST_DIR := test
