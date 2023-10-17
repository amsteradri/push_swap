/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:02:59 by adgutier          #+#    #+#             */
/*   Updated: 2023/10/17 12:24:01 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_range_int(const char *str_nbr)
{
	long	l;
	long	is_signed;

	l = 0;
	is_signed = (long)(str_nbr[0] == '-');
	while (*str_nbr != '\0' && l < INT_MAX)
	{
		if (ft_isdigit(*str_nbr))
			l = l * 10 + *str_nbr - '0';
		str_nbr++;
	}
	if (l > INT_MAX + is_signed)
		return (0);
	return (1);
}

void	error(int err)
{
	if (err == 0 || err == -1)
	{
		ft_putstr("Error:number exceeds int\n");
		exit(0);
	}
	return ;
}

void	write_stack(t_stacks *stack)
{
	t_stacks	*current;

	current = stack;
	ft_putstr("\n-------------------\n");
	while (current != NULL)
	{
		ft_putnbr(current->n);
		if (current->next != NULL)
		{
			ft_putstr("\n");
		}
		current = current->next;
	}
	ft_putstr("\n");
}

void	write_stack_b(t_stacks *stack)
{
	t_stacks	*current;

	current = stack;
	while (current != NULL)
	{
		ft_putstr("        ");
		ft_putnbr(current->n);
		if (current->next != NULL)
		{
			ft_putstr("\n");
		}
		current = current->next;
	}
	ft_putstr("\n-------------------\n");
}
