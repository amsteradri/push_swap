/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:12:10 by adgutier          #+#    #+#             */
/*   Updated: 2023/09/14 14:58:18 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(struct stacks **current)
{
	struct stacks	*seclast;
	struct stacks	*temp;

	if (*current == NULL || (*current)->next == NULL)
	{
		ft_putstr("rra: error\n");
		return ;
	}
	seclast = NULL;
	temp = *current;
	while (temp->next->next != NULL)
	{
		seclast = temp;
		temp = temp->next;
	}
	temp->next->next = *current;
	*current = temp->next;
	temp->next = NULL;
	normal_pos(current);
	ft_putstr("rra\n");
}

void	rrb(struct stacks **current)
{
	struct stacks	*seclast;
	struct stacks	*temp;

	if (*current == NULL || (*current)->next == NULL)
	{
		ft_putstr("rrb: error\n");
		return ;
	}
	seclast = NULL;
	temp = *current;
	while (temp->next->next != NULL)
	{
		seclast = temp;
		temp = temp->next;
	}
	temp->next->next = *current;
	*current = temp->next;
	temp->next = NULL;
	normal_pos(current);
	ft_putstr("rrb\n");
}

void	ra(struct stacks **current)
{
	struct stacks	*new_node;
	struct stacks	*first;

	new_node = *current;
	*current = current[0]->next;
	first = new_node;
	while (new_node->next != NULL)
		new_node = new_node->next;
	new_node->next = first;
	first->next = NULL;
	normal_pos(&new_node);
	ft_putstr("ra\n");
}

void	rb(struct stacks **current)
{
	struct stacks	*new_node;
	struct stacks	*first;

	new_node = *current;
	*current = current[0]->next;
	first = new_node;
	while (new_node->next != NULL)
		new_node = new_node->next;
	new_node->next = first;
	first->next = NULL;
	normal_pos(&new_node);
	ft_putstr("rb\n");
}

void	rr(struct stacks **current_a, struct stacks **current_b)
{
	struct stacks	*temp_a;
	struct stacks	*temp_b;
	struct stacks	*first_a;
	struct stacks	*first_b;

	temp_a = *current_a;
	*current_a = (*current_a)->next;
	temp_b = *current_b;
	*current_b = (*current_b)->next;
	first_a = temp_a;
	first_b = temp_b;
	while (temp_a->next != NULL)
		temp_a = temp_a->next;
	while (temp_b->next != NULL)
		temp_b = temp_b->next;
	temp_a->next = first_a;
	temp_b->next = first_b;
	first_a->next = NULL;
	first_b->next = NULL;
	normal_pos(current_a);
	normal_pos(current_b);
	ft_putstr("rr\n");
}
