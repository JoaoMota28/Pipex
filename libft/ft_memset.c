/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:36:42 by jomanuel          #+#    #+#             */
/*   Updated: 2024/10/28 15:38:19 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;
	unsigned int	i;

	i = 0;
	temp = (unsigned char *) s;
	while (i < n)
	{
		*temp = (unsigned char) c;
		temp++;
		i++;
	}
	return (s);
}
