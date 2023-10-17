/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:51:20 by adgutier          #+#    #+#             */
/*   Updated: 2023/10/17 12:02:52 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct stacks
{
	int				n;
	int				min_pos;
	int				pos;
	struct stacks	*next;
}					t_stacks;

typedef struct moves
{
	char			*posi;
	void			*next;
	void			*befo;
}					t_moves;

typedef struct situation
{
	t_stacks			*stack_a;
	t_stacks			*stack_b;
	t_stacks			*final_a;
	t_stacks			*final_b;
	t_moves				*movements;
	t_moves				*prev_move;

}					t_situation;

typedef struct solving
{
	t_stacks			*stack_a;
	t_stacks			*stack_b;
	t_moves				*movement;
}					t_solving;

char				*ft_get_args(char *str);
void				ft_putchar(char c);
void				ft_putstr(char *str);
char				*ft_strcpy(char *dest, char *src);
int					ft_atoi(const char *str);
void				create_stacks(t_situation *situ, int argc, char **argv);
void				rra(struct stacks **current);
void				rrb(struct stacks **current);
void				ra(struct stacks **current);
void				rb(struct stacks **current);
void				rr(struct stacks **current_a, struct stacks **current_b);
void				write_stack(t_stacks *stack);
void				write_stack_b(t_stacks *stack);
void				ft_putnbr(int nb);
void				error(int err);
void				ft_sa(struct stacks **current);
void				ft_ss(struct stacks **stack_a, struct stacks **stack_b);
void				ft_secondpos(struct stacks *current);
void				push_a(struct stacks **current_a,
						struct stacks **current_b);
void				push_b(struct stacks **current_a,
						struct stacks **current_b);
int					check_argv(char *argv);
void				check_only_nums2(char **argv);
void				check_dupe(struct stacks **current);
void				sort_small(int argc, struct situation *current);
void				check_sorted(struct stacks **current);
void				sort_4s(int argc, struct situation *current);
void				sort_4b(int argc, struct situation *current);
void				sort_5s(int argc, struct situation *current);
void				sort_5b(int argc, struct situation *current);
int					smallest_element(t_stacks **stack);
int					smallest_element_in_chunk(t_stacks **stack, int min);
int					biggest_element(t_stacks **stack);
int					biggest_num(t_stacks **stack);
int					biggest_element_in_chunk(t_stacks **stack);
void				move_big(int argc, struct situation *current, int chunk,
						int prev);
void				sort_big(int argc, struct situation *current);
void				all_sort_big(int argc, struct situation *current);
void				fill_pos(t_stacks **stack, int num);
void				fill_small(int argc, t_stacks **stack, int num);
void				normal_pos(t_stacks **stack);
int					stack_size(t_stacks **stack);
void				move_big_toa(int argc, struct situation *current);
int					chunk_size(int argc);
int					smallest_element_for_small(t_stacks **stack);
void				ft_bzero(void *s, unsigned int n);
void				*ft_calloc(size_t numcarac, size_t size);
char				**ft_split(const char *s, char c);
int					ft_isdigit(int c);
void				move_remaining(int argc, struct situation *current,
						int prev, int chunk_size1);
int					valid_range_int(const char *str_nbr);
void				print_and_exit(void);
#endif