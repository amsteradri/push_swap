# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 10:47:49 by adgutier          #+#    #+#              #
#    Updated: 2023/09/21 10:07:06 by adgutier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

SRCS			= main.c ft_putchar.c ft_putstr.c ft_strcpy.c push_swap_utils.c ft_atoi.c moves.c push_swap.c sorting_small.c sorting_small_5.c sort_big.c ft_calloc.c ft_bzero.c ft_split.c ft_isdigit.c sorting_small_utils.c sorting_small_utils2.c moves2.c create_stacks.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc

CFLAGS			= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(SRCS)
		$(CC) $(CFLAGS) -c $(SRCS)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)
		rm -rf push_swap.a
		rm -rf push_swap

wclean:
		del $(OBJS)

wfclean: clean
		del $(NAME)
		del push_swap.a
		del push_swap

re: fclean all

.PHONY: all re clean fclean
