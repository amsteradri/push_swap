/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:17:28 by adgutier          #+#    #+#             */
/*   Updated: 2023/09/14 11:05:10 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normal_pos(t_stacks **stack)
{
	t_stacks	*temp;
	int			num;

	num = 1;
	temp = *stack;
	while (temp != NULL)
	{
		temp->pos = num;
		temp = temp->next;
		num++;
	}
}
