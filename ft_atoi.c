/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:21:27 by adgutier          #+#    #+#             */
/*   Updated: 2022/09/27 13:01:36 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	while (*str && (*str == 32 || (*str >= 9 && *str <= 13)))
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = (-1);
		++str;
	}
	result = 0;
	while (ft_isdigit(*str))
	{
		result = (result * 10) + (*str - '0') * sign;
		if (result > INT_MAX)
			return (-1);
		else if (result < INT_MIN)
			return (0);
		++str;
	}
	return (result);
}
