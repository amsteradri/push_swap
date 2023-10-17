/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:36:29 by adgutier          #+#    #+#             */
/*   Updated: 2023/09/14 11:05:51 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(int argc, struct situation *current)
{
	if (argc == 2)
	{
		if (current->stack_a->n > current->stack_a->next->n)
			ft_sa(&current->stack_a);
	}
	if (argc == 3)
	{
		if (current->stack_a->n > current->stack_a->next->n)
			ft_sa(&current->stack_a);
		if (current->stack_a->n > current->stack_a->next->next->n)
			rra(&current->stack_a);
		if (current->stack_a->next->n > current->stack_a->next->next->n)
		{
			rra(&current->stack_a);
			ft_sa(&current->stack_a);
		}
	}
}

void	sort_4s(int argc, struct situation *current)
{
	int	i;

	i = smallest_element_for_small(&current->stack_a);
	if (argc == 4)
	{
		if (i == 1 || i == 2)
		{
			if (i == 1)
			{
				push_b(&current->stack_a, &current->stack_b);
				sort_small(3, current);
				push_a(&current->stack_a, &current->stack_b);
			}
			if (i == 2)
			{
				ra(&current->stack_a);
				push_b(&current->stack_a, &current->stack_b);
				sort_small(3, current);
				push_a(&current->stack_a, &current->stack_b);
			}
		}
		else
			sort_4b(argc, current);
	}
}

void	sort_4b(int argc, struct situation *current)
{
	int	i;

	i = smallest_element_for_small(&current->stack_a);
	if (argc == 4)
	{
		if (i == 3 || i == 4)
		{
			if (i == 3)
			{
				ra(&current->stack_a);
				ra(&current->stack_a);
				push_b(&current->stack_a, &current->stack_b);
			}
			if (i == 4)
			{
				rra(&current->stack_a);
				push_b(&current->stack_a, &current->stack_b);
			}
		}
		sort_small(3, current);
		push_a(&current->stack_a, &current->stack_b);
	}
}

int	smallest_element(t_stacks **stack)
{
	int			min;
	int			pos;
	t_stacks	*temp;
	t_stacks	*temp_2;

	min = INT_MAX;
	temp = *stack;
	temp_2 = *stack;
	while (temp != NULL)
	{
		if (min > temp->n && temp->min_pos == 0)
			min = temp->n;
		temp = temp->next;
	}
	pos = 1;
	while (temp_2 && temp_2->n != min)
	{
		pos++;
		temp_2 = temp_2->next;
	}
	if (temp_2 == NULL)
		return (0);
	return (pos);
}

int	smallest_element_for_small(t_stacks **stack)
{
	int			min;
	int			pos;
	t_stacks	*temp;
	t_stacks	*temp_2;

	min = INT_MAX;
	temp = *stack;
	temp_2 = *stack;
	while (temp != NULL)
	{
		if (min > temp->n)
			min = temp->n;
		temp = temp->next;
	}
	pos = 1;
	while (temp_2 && temp_2->n != min)
	{
		pos++;
		temp_2 = temp_2->next;
	}
	if (temp_2 == NULL)
		return (0);
	return (pos);
}
