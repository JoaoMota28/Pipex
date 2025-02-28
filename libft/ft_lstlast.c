/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:35:36 by jomanuel          #+#    #+#             */
/*   Updated: 2024/11/12 14:44:01 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;
	t_list	*next;

	current = lst;
	if (current == NULL)
		return (current);
	next = current->next;
	while (next != NULL)
	{
		current = current->next;
		next = next->next;
	}
	return (current);
}
