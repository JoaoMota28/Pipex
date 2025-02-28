/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:41:29 by jomanuel          #+#    #+#             */
/*   Updated: 2024/11/15 17:48:51 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little[i])
		return ((char *)big);
	while (big[i] && i <= len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len && little[j])
		{
			j++;
		}
		if (j == ft_strlen(little))
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
