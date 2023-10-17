/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:57:02 by adgutier          #+#    #+#             */
/*   Updated: 2023/10/17 12:52:21 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr(int nb)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		ft_putchar('-');
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
}

size_t	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	leaks(void)
{
	system("leaks -q push_swap");
}

void	init_so_long(t_situation *current, int leng)
{
	check_dupe(&current->stack_a);
	check_sorted(&current->stack_a);
	normal_pos(&current->stack_a);
	fill_small(leng, &current->stack_a, 1);
	sort_small(leng, current);
	sort_4s(leng, current);
	sort_5s(leng, current);
	if (leng > 5)
	{
		sort_big(leng, current);
		normal_pos(&current->stack_b);
		move_big_toa(leng, current);
	}
}

int	main(int argc, char **argv)
{
	t_situation	current;
	int			leng;

	//atexit(leaks);
	if (argc != 2)
		exit(-1);
	if(!ft_isdigit(argv[1][0]) && ft_strlen(argv[1]) == 1)
		print_and_exit();
	check_argv(*argv);
	create_stacks(&current, argc, argv);
	leng = stack_size(&current.stack_a);
	if (leng == 1)
		exit(0);
	init_so_long(&current, leng);
	while (current.stack_a)
	{
		free(current.stack_a);
		current.stack_a = current.stack_a->next;
	}
	free(current.stack_a);
	free(current.stack_b);
	return (0);
}
