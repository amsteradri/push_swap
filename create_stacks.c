/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:06:21 by adgutier          #+#    #+#             */
/*   Updated: 2023/09/21 10:14:39 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*initialize_stack(int value)
{
	t_stacks	*stack;

	stack = (t_stacks *)malloc(sizeof(t_stacks));
	error((int)(stack));
	stack->n = value;
	stack->next = NULL;
	stack->min_pos = 0;
	return (stack);
}

void	initialize_stacks(t_situation *situ)
{
	situ->movements = NULL;
	situ->stack_a = NULL;
	situ->stack_b = NULL;
}

void	populate_stack_a(t_situation *situ, char **split)
{
	int			i;
	t_stacks	*current;

	i = 0;
	current = NULL;
	while (split[i])
	{
		if (!(valid_range_int(split[i])))
			error(0);
		if (current == NULL)
		{
			situ->stack_a = initialize_stack(ft_atoi(split[i]));
			current = situ->stack_a;
		}
		else
		{
			current->next = initialize_stack(ft_atoi(split[i]));
			current = current->next;
		}
		i++;
	}
	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	create_stacks(t_situation *situ, int argc, char **argv)
{
	char	**split;

	initialize_stacks(situ);
	split = ft_split(argv[1], ' ');
	error(argc == 2);
	populate_stack_a(situ, split);
}
