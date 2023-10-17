/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:51:23 by adgutier          #+#    #+#             */
/*   Updated: 2023/10/17 12:02:43 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dupe(struct stacks **current)
{
	struct stacks	*new_node;
	struct stacks	*aux;

	new_node = *current;
	while (new_node != NULL)
	{
		aux = new_node->next;
		while (aux != NULL)
		{
			if (new_node->n == aux->n)
			{
				ft_putstr("Error duped nums\n");
				exit(0);
			}
			aux = aux->next;
		}
		new_node = new_node->next;
	}
}

 void	print_and_exit(void)
{
	printf("Error: Invalid parameters\n");
	exit(-1);
}

int	check_argv(char *argv)
{
	int	i;

	i = 13;
	while (argv[i])
	{
		while (argv[i] == '-' || argv[i] == '+' || argv[i] == ' ')
			i++;
		if (!ft_isdigit(argv[i]))
		{
			if (argv[i] == ' ' && i != 0)
			{
				i++;
				continue ;
			}
			if (argv[i + 1] && (ft_isdigit(argv[i + 1]) || argv[i + 1] == '-'
					|| argv[i + 1] == '+'))
				print_and_exit();
			else
				print_and_exit();
		}
		i++;
	}
	return (1);
}

void	check_sorted(struct stacks **current)
{
	struct stacks	*new_node;

	new_node = *current;
	while (new_node->next != NULL)
	{
		if (new_node->n > new_node->next->n)
		{
			break ;
		}
		new_node = new_node->next;
	}
	if (new_node->next == NULL)
	{
		ft_putstr("Error Already sorted list\n");
		exit(0);
	}
}
