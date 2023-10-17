/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:14:06 by adgutier          #+#    #+#             */
/*   Updated: 2023/09/14 10:41:20 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_big(int argc, struct situation *current, int chunk, int prev)
{
	int	aux;
	int	len;

	prev = 0;
	aux = current->stack_a->pos;
	if (current->stack_a->min_pos > chunk)
	{
		while (current->stack_a->min_pos > chunk)
			ra(&current->stack_a);
	}
	if (current->stack_a->min_pos <= chunk && current->stack_a->min_pos > prev)
	{
		len = argc - 1;
		if (current->stack_a->pos >= len / 2)
		{
			while (aux++ < argc)
				rra(&current->stack_a);
		}
		if (current->stack_a->pos < len / 2)
		{
			while (aux-- > 1)
				ra(&current->stack_a);
		}
		push_b(&current->stack_a, &current->stack_b);
	}
}

void	sort_big(int argc, struct situation *current)
{
	int	iteraciones;
	int	i;
	int	chunk;
	int	chunk_size1;
	int	prev;

	chunk_size1 = chunk_size(argc);
	iteraciones = 0;
	chunk = chunk_size(argc);
	prev = 0;
	while (iteraciones++ < ((argc - 1) / chunk_size1))
	{
		i = 0;
		while (i < chunk_size1)
		{
			move_big(argc, current, chunk, prev);
			i++;
		}
		prev = chunk;
		if (chunk + chunk_size1 > argc - 1)
			chunk = argc - chunk_size1 - ((argc - 1) % chunk_size1);
		else
			chunk = chunk + chunk_size1;
	}
	move_remaining(argc, current, prev, chunk_size1);
}

void	move_remaining(int argc, struct situation *current,
		int prev, int chunk_size1)
{
	int	i;
	int	chunk;

	i = 0;
	while (i < ((argc - 1) % chunk_size1))
	{
		chunk = argc - 1;
		move_big(argc, current, chunk, prev);
		i++;
	}
	push_b(&current->stack_a, &current->stack_b);
}

void	move_big_toa(int argc, struct situation *current)
{
	int	len;
	int	big_pos;
	int	i;

	i = 0;
	(void)argc;
	len = stack_size(&current->stack_b);
	while (i++ < argc - 1)
	{
		big_pos = biggest_element(&current->stack_b);
		len = stack_size(&current->stack_b);
		if (big_pos >= len / 2)
		{
			while (big_pos++ <= len)
				rrb(&current->stack_b);
		}
		if (big_pos < len / 2)
		{
			while (big_pos-- > 1)
				rb(&current->stack_b);
		}
		push_a(&current->stack_a, &current->stack_b);
	}
	push_a(&current->stack_a, &current->stack_b);
}

int	chunk_size(int argc)
{
	int	chunk;

	chunk = 0;
	if (argc < 100)
		chunk = 10;
	if (argc >= 100)
		chunk = 20;
	return (chunk);
}
