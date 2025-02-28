/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:38:20 by jomanuel          #+#    #+#             */
/*   Updated: 2025/02/25 17:57:49 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pip(t_pipe *pip)
{
	pip->path = NULL;
	pip->spath = NULL;
	pip->args = NULL;
	pip->cmd = NULL;
	pip->pids = NULL;
	pip->pipes = NULL;
	pip->heredoc = 0;
	pip->cmd_num = 0;
}

void	free_all(t_pipe *pip)
{
	int	i;

	i = 0;
	while (pip->spath && pip->spath[i])
		free(pip->spath[i++]);
	i = 0;
	while (pip->args && pip->args[i])
		free(pip->args[i++]);
	i = 0;
	while (i < pip->cmd_num - 1)
		free(pip->pipes[i++]);
	free(pip->pipes);
	free(pip->cmd);
	free(pip->spath);
	free(pip->args);
	free(pip->pids);
}

void	terminate(char *msg, t_pipe *pip, int flag)
{
	if (flag == 1)
		perror(msg);
	else if (flag == 2)
		ft_putendl_fd(msg, 2);
	else if (flag == 3)
	{
		ft_putendl_fd(msg, 2);
		free(msg);
	}
	free_all(pip);
	exit(1);
}
