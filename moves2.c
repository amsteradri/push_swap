/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:09:45 by adgutier          #+#    #+#             */
/*   Updated: 2023/09/14 14:55:11 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sa(struct stacks **current)
{
	int	temp;

	if (*current != NULL && (*current)->next != NULL)
	{
		temp = (*current)->n;
		(*current)->n = (*current)->next->n;
		(*current)->next->n = temp;
		normal_pos(current);
		ft_putstr("sa\n");
	}
	else
	{
		ft_putstr("sa: error\n");
	}
}

void	ft_ss(struct stacks **stack_a, struct stacks **stack_b)
{
	struct stacks	*new_node_a;
	struct stacks	*new_node_b;

	if (*stack_a == NULL || (*stack_a)->next == NULL || *stack_b == NULL
		|| (*stack_b)->next == NULL)
	{
		ft_putstr("ss: error\n");
		return ;
	}
	new_node_a = *stack_a;
	new_node_b = *stack_b;
	swap(&new_node_a->n, &new_node_a->next->n);
	swap(&new_node_b->n, &new_node_b->next->n);
	normal_pos(stack_a);
	normal_pos(stack_b);
	ft_putstr("ss\n");
}

void	push_b(struct stacks **current_a, struct stacks **current_b)
{
	struct stacks	*new_node_a;
	struct stacks	*new_node_b;

	if (*current_a == NULL)
	{
		ft_putstr("pb: error\n");
		return ;
	}
	new_node_a = *current_a;
	if (*current_b == NULL)
	{
		*current_b = new_node_a;
		*current_a = new_node_a->next;
		new_node_a->next = NULL;
	}
	else
	{
		new_node_b = *current_b;
		*current_b = new_node_a;
		*current_a = new_node_a->next;
		new_node_a->next = new_node_b;
	}
	normal_pos(current_a);
	normal_pos(current_b);
	ft_putstr("pb\n");
}

void	push_a(struct stacks **current_a, struct stacks **current_b)
{
	struct stacks	*new_node_b;
	struct stacks	*new_node_a;

	if (*current_b == NULL)
	{
		ft_putstr("pa: error\n");
		return ;
	}
	new_node_b = *current_b;
	new_node_a = new_node_b;
	new_node_b = new_node_b->next;
	new_node_a->next = *current_a;
	*current_a = new_node_a;
	*current_b = new_node_b;
	normal_pos(current_a);
	normal_pos(current_b);
	ft_putstr("pa\n");
}
