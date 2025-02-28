/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:39:06 by jomanuel          #+#    #+#             */
/*   Updated: 2024/11/04 13:32:53 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	length;
	char	*array;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		length = 0;
	else
		length = ft_strlen(s + start);
	i = 0;
	if (length >= len)
		array = (char *)malloc((len + 1) * sizeof(char));
	else
		array = (char *)malloc((length + 1) * sizeof(char));
	if (array == NULL)
		return (array);
	while (i < len && i < length)
	{
		array[i] = s[start + i];
		i++;
	}
	array[i] = '\0';
	return (array);
}
