/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:56:33 by jomanuel          #+#    #+#             */
/*   Updated: 2024/11/15 11:26:19 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	i = 0;
	if (size == 0)
		i = srclen;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
	{
		dst[i] = '\0';
	}
	return (srclen);
}

/*#include <string.h>
#include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	char	src[] = "coucou";
	char	dest[20];
	char	dest1[20];

	int	i = ft_strlcpy(dest, src, -1);
	printf("string: %s\n len: %d\n srclen: %d\n\n", dest, i, ft_strlen(src));
	int j = strlcpy(dest1, src, -1);
	printf("string: %s\n len: %d\n srclen: %d", dest1, j, ft_strlen(src));
	return (0);
}*/