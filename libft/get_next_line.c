/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:40:22 by jomanuel          #+#    #+#             */
/*   Updated: 2025/01/31 18:51:30 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(char *s, char del)
{
	size_t	counter;

	counter = 0;
	if (!s)
		return (0);
	while (s[counter] && s[counter] != del)
		counter++;
	if (s[counter] == '\n')
		counter++;
	return (counter);
}

void	ft_strlcpy_gnl(char *dest, char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
}

char	*join_and_clean_buff(char *line, char *buff)
{
	char	*new_line;
	size_t	len_line;
	size_t	len_buff;
	size_t	i;

	i = 0;
	len_line = ft_strlen_gnl(line, '\0');
	len_buff = ft_strlen_gnl(buff, '\n');
	new_line = malloc((len_line + len_buff + 1) * sizeof(char));
	if (!new_line)
		return (free(line), NULL);
	new_line[len_line + len_buff] = '\0';
	ft_strlcpy_gnl(new_line, line, len_line);
	ft_strlcpy_gnl(new_line + len_line, buff, len_buff);
	free(line);
	while (buff[len_buff + i])
	{
		buff[i] = buff[len_buff + i];
		i++;
	}
	buff[i] = '\0';
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			chars_read;

	line = NULL;
	chars_read = 1;
	while (fd >= 0 && fd < FOPEN_MAX && BUFFER_SIZE > 0 && chars_read > 0)
	{
		if (buff[fd][0])
		{
			line = join_and_clean_buff(line, buff[fd]);
			if (!line)
				return (NULL);
			if (line[ft_strlen_gnl(line, '\n') - 1] == '\n')
				break ;
		}
		else
		{
			chars_read = read(fd, buff[fd], BUFFER_SIZE);
			if (chars_read < 0)
				return (free(line), NULL);
			buff[fd][chars_read] = '\0';
		}
	}
	return (line);
}
