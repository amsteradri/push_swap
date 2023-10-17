/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:42:42 by adgutier          #+#    #+#             */
/*   Updated: 2022/11/03 10:29:09 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stacks	*ft_lstlast(stacks *lst)
{
	if (!lst)
		return (NULL);
	while (lst ->next != NULL)
		lst = lst->next;
	if (lst ->next == NULL)
		return (lst);
	return (lst);
}
