/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:54:37 by jomanuel          #+#    #+#             */
/*   Updated: 2025/01/31 17:16:33 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countwords(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s[i] != c && s[i])
		count++;
	if (s[i])
		i++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			count ++;
		i++;
	}
	return (count);
}

size_t	wordlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	**my_split(char **array, char const *s, char c)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < countwords(s, c))
	{
		if (s[j] != c)
		{
			str = (char *)ft_calloc((wordlen(s + j, c) + 1), sizeof(char));
			if (str == NULL)
			{
				ft_freeall(array);
				return (NULL);
			}
			ft_strlcpy(str, s + j, wordlen(s + j, c) + 1);
			array[i] = str;
			i++;
			j += wordlen(s + j, c);
		}
		j++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (s == NULL)
		return (NULL);
	array = (char **)ft_calloc((countwords(s, c) + 1), sizeof(char *));
	if (array == NULL)
		return (NULL);
	return (my_split(array, s, c));
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	**array = ft_split("hello!", 32);
// 	int		i = 0;

// 	while (array[i] != NULL)
// 	{
// 		printf("%s\n", array[i]);
// 		free(array[i]);
// 		i++;
// 	}
// 	free(array);
// 	return (0);
// }
