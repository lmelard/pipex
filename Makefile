# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 18:23:10 by lmelard           #+#    #+#              #
#    Updated: 2022/07/01 16:15:53 by lmelard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = ./srcs/ft_get_path.c \
	./srcs/ft_get_error.c \
	./srcs/ft_child_process.c \
	./srcs/ft_free.c \
	./srcs/ft_init.c \
	./srcs/ft_write_error.c \
	./srcs/main.c

OBJS = ${SRCS:.c=.o}

CC = gcc
RM = rm -f

CFLAGS = -Wall -Werror -Wextra

LIBFLAGS = -L./libft -lft

.c.o:
	${CC} ${CFLAGS} -g3 -c $< -o ${<:.c=.o}

all: ${NAME}

$(NAME): ${OBJS}
	@echo "Compiling the libft..."
	@make -C libft
	@echo "Compiling the mandatory part..."
	${CC} ${CFLAGS} -g3 -o ${NAME} ${OBJS} ${LIBFLAGS}
	@echo "---> pipex is ready to be used <--- USAGE: ./pipex [file1] [cmd1] [cmd2] [file2]"

clean:
	@echo "Removing libft's objects..."
	@make clean -C libft
	@echo "Removing pipex's mandatories objects..."
	${RM} ${OBJS}

fclean: clean
	@echo "Removing libft archive..."
	@make fclean -C libft
	@echo "Removing pipex's ..."
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re