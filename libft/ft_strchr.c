/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:08:17 by jomanuel          #+#    #+#             */
/*   Updated: 2024/11/14 16:28:06 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (unsigned char) c)
		return ((char *)(s + i));
	return (NULL);
}

/*int main(void)
{
	char	*str = "teste";
	int		c = '\0' + 1024;

	printf("%s\n", ft_strchr(str, c));
	printf("%s\n", strchr(str, c));
}*/
