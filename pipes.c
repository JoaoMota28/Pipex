/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:58:35 by jomanuel          #+#    #+#             */
/*   Updated: 2025/02/28 12:32:56 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_pipes(t_pipe *pip)
{
	int	i;

	pip->pipes = malloc(sizeof(int *) * (pip->cmd_num - 1));
	if (!pip->pipes)
		terminate("Error creating pipes", pip, 1);
	i = 0;
	while (i < pip->cmd_num - 1)
	{
		pip->pipes[i] = malloc(sizeof(int) * 2);
		pipe(pip->pipes[i]);
		i++;
	}
}

void	duplicate_pipes(t_pipe *pip, int num)
{
	if (num == 0)
	{
		dup2(pip->pipes[num][1], STDOUT_FILENO);
		dup2(pip->fd_in, STDIN_FILENO);
	}
	else if (num > 0 && num < pip->cmd_num - 1)
	{
		dup2(pip->pipes[num][1], STDOUT_FILENO);
		dup2(pip->pipes[num - 1][0], STDIN_FILENO);
	}
	else
	{
		dup2(pip->fd_out, STDOUT_FILENO);
		dup2(pip->pipes[num - 1][0], STDIN_FILENO);
	}
}

void	close_unused_pipes(t_pipe *pip, int num)
{
	int	i;

	i = 0;
	while (i < pip->cmd_num - 1)
	{
		if (i == num)
		{
			if (num == pip->cmd_num - 1)
				close(pip->pipes[i][1]);
			else
				close(pip->pipes[i][0]);
		}
		else if (i == num - 1)
			close(pip->pipes[i][1]);
		else
		{
			close(pip->pipes[i][0]);
			close(pip->pipes[i][1]);
		}
		i++;
	}
}

void	close_all_pipes(t_pipe *pip)
{
	int	i;

	i = 0;
	if (pip->fd_in > 0)
		close(pip->fd_in);
	if (pip->fd_out > 0)
		close(pip->fd_out);
	while (i < pip->cmd_num - 1)
	{
		if (pip->pipes[i][0] >= 0)
			close(pip->pipes[i][0]);
		if (pip->pipes[i][1] >= 0)
			close(pip->pipes[i][1]);
		i++;
	}
}
