# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 10:25:24 by jwolfram          #+#    #+#              #
#    Updated: 2024/09/27 14:51:47 by jwolfram         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

## REMOVE -G LATER
CC := cc -g

MLXFLAGS := -lmlx -lXext -lX11 -lm

CFLAGS := -Wall -Wextra -Werror

RM := rm -fr

INCLUDES := -I./includes/ -I./libft/includes

RED := \033[1;31m

GREEN := \033[1;32m

BLUE := \033[1;34m

DEFAULT := \033[0m 

SRCS_DIR := src

SRCS := main \
		init \
		map \
		game \
		events \
		move \
		exit \

OBJS_DIR := obj

OBJS := ${SRCS:%=${OBJS_DIR}/%.o}

OBJS_SORT := ${sort ${dir ${OBJS}}}

LIBFT_DIR := libft

LIBFT := libft/libft.a

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	@${CC} ${CFLAGS} ${MLXFLAGS} $^ ${INCLUDES} -o $@
	@echo "${GREEN}--------------------------${DEFAULT}"
	@echo "${GREEN}   COMPILATION COMPLETE   ${DEFAULT}"
	@echo "${GREEN}--------------------------${DEFAULT}"
	
${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c | ${OBJS_SORT}
	@${CC} ${CFLAGS} -c $< ${INCLUDES} -o $@

${OBJS_SORT}:
	@mkdir -p $@

${LIBFT}:
	@${MAKE} -C ${LIBFT_DIR}

clean:
	@${MAKE} $@ -C ${LIBFT_DIR}
	@${RM} ${OBJS_DIR}
	@echo "${BLUE}--------------------------${DEFAULT}"
	@echo "${BLUE}     CLEANUP COMPLETE     ${DEFAULT}"
	@echo "${BLUE}--------------------------${DEFAULT}"

fclean: clean
	@${MAKE} $@ -C ${LIBFT_DIR}
	@${RM} ${NAME}

re: fclean all

### REMOVE NORM LATER
norm:
	norminette ${SRCS_DIR}

.PHONY: all clean fclean re norm
