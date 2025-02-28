/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:59:02 by jomanuel          #+#    #+#             */
/*   Updated: 2024/11/09 18:22:33 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	numsize(int n)
{
	size_t	size;
	long	nb;

	size = 0;
	nb = n;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		size++;
		nb = -nb;
	}
	while (nb > 0)
	{
		size++;
		nb = nb / 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*array;
	long	num;

	size = numsize(n);
	num = n;
	if (num < 0)
		num = -num;
	array = (char *)malloc((size + 1) * sizeof(char));
	if (!array)
		return (NULL);
	array[size] = '\0';
	while (size-- > 0)
	{
		array[size] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		array[0] = '-';
	return (array);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%s", ft_itoa(-2147483648LL));
}*/
