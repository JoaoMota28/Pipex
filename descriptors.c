/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descriptors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:00:07 by jomanuel          #+#    #+#             */
/*   Updated: 2025/02/28 12:36:57 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_in(char **argv, t_pipe *pip)
{
	if (pip->heredoc)
		heredoc(argv, pip);
	else
		pip->fd_in = open(argv[1], O_RDONLY);
}

void	open_out(int argc, char **argv, t_pipe *pip)
{
	if (pip->heredoc)
		pip->fd_out = open(argv[argc - 1], O_CREAT | O_APPEND | O_WRONLY, 0644);
	else
		pip->fd_out = open(argv[argc - 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (pip->fd_out < 0 && access(argv[argc - 1], W_OK))
		terminate(argv[argc - 1], pip, 1);
}

void	heredoc(char **argv, t_pipe *pip)
{
	int		fd[2];
	char	*line;

	pipe(fd);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			terminate("Invalid input.", pip, 0);
		if (!ft_strncmp(argv[2], line, ft_strlen(argv[2])) && \
			(ft_strlen(argv[2]) == ft_strlen(line) - 1))
			break ;
		ft_putstr_fd(line, fd[1]);
		free(line);
	}
	free(line);
	close(fd[1]);
	pip->fd_in = fd[0];
}
