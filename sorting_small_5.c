/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:39:01 by adgutier          #+#    #+#             */
/*   Updated: 2023/09/21 10:23:38 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5s_part1(struct situation *current, int i)
{
	if (i == 1)
	{
		push_b(&current->stack_a, &current->stack_b);
		sort_4s(4, current);
		push_a(&current->stack_a, &current->stack_b);
	}
	if (i == 2)
	{
		ra(&current->stack_a);
		push_b(&current->stack_a, &current->stack_b);
		sort_4s(4, current);
		push_a(&current->stack_a, &current->stack_b);
	}
	if (i == 3)
	{
		ra(&current->stack_a);
		ra(&current->stack_a);
		push_b(&current->stack_a, &current->stack_b);
		sort_4s(4, current);
		push_a(&current->stack_a, &current->stack_b);
	}
}

void	sort_5s(int argc, struct situation *current)
{
	int	i;

	i = smallest_element_for_small(&current->stack_a);
	if (argc == 5)
	{
		if (i == 1 || i == 2 || i == 3)
		{
			sort_5s_part1(current, i);
		}
		else
		{
			sort_5b(argc, current);
		}
	}
}

void	sort_5b(int argc, struct situation *current)
{
	int	i;

	i = smallest_element_for_small(&current->stack_a);
	if (argc == 5)
	{
		if (i == 4)
		{
			rra(&current->stack_a);
			rra(&current->stack_a);
			push_b(&current->stack_a, &current->stack_b);
			sort_4s(4, current);
			push_a(&current->stack_a, &current->stack_b);
		}
		if (i == 5)
		{
			rra(&current->stack_a);
			push_b(&current->stack_a, &current->stack_b);
			sort_4s(4, current);
			push_a(&current->stack_a, &current->stack_b);
		}
	}
}
