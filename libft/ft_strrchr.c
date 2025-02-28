/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:24:12 by jomanuel          #+#    #+#             */
/*   Updated: 2024/11/14 16:28:19 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (s[i] == (unsigned char) c)
		return ((char *)(s + i));
	while (--i >= 0)
	{
		if (s[i] == (unsigned char) c)
			return ((char *)(s + i));
	}
	return (NULL);
}

/*int main(void)
{
	char	*str = "teste";
	int		c = '\0';

	printf("%s\n", ft_strrchr(str, c));
}*/
