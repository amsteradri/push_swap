/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:13:54 by adgutier          #+#    #+#             */
/*   Updated: 2023/09/14 11:05:40 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest_element_in_chunk(t_stacks **stack, int min)
{
	int			pos;
	t_stacks	*temp;
	t_stacks	*temp_2;

	temp = *stack;
	temp_2 = *stack;
	if (min)
	{
		while (temp != NULL)
		{
			if (min > temp->n)
				min = temp->n;
			temp = temp->next;
		}
	}
	pos = 1;
	while (temp_2->n != min)
	{
		pos++;
		temp_2 = temp_2->next;
	}
	return (pos);
}

int	biggest_element(t_stacks **stack)
{
	t_stacks	*temp;
	int			biggest;
	int			min_pos;

	temp = *stack;
	biggest = INT_MIN;
	min_pos = 0;
	while (temp != NULL)
	{
		if (temp->n > biggest)
		{
			biggest = temp->n;
			min_pos = temp->pos;
		}
		temp = temp->next;
	}
	return (min_pos);
}

int	stack_size(t_stacks **stack)
{
	t_stacks	*tmp;
	int			i;

	i = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	fill_pos(t_stacks **stack, int num)
{
	int			minpos;
	t_stacks	*temp;

	temp = *stack;
	minpos = smallest_element(stack);
	while (minpos > 1)
	{
		temp = temp->next;
		minpos--;
	}
	temp->min_pos = num;
}

void	fill_small(int argc, t_stacks **stack, int num)
{
	int			count;
	t_stacks	*temp;

	temp = *stack;
	count = 1;
	while (count <= argc)
	{
		fill_pos(stack, num);
		num++;
		count++;
	}
}
