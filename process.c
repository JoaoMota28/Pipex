/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:02:07 by jomanuel          #+#    #+#             */
/*   Updated: 2025/02/28 11:02:27 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char **argv, char **envp, t_pipe *pip, int num)
{
	int	arg_nr;

	arg_nr = 2 + pip->heredoc + num;
	if (num == 0)
	{
		if (pip->fd_in < 0)
			terminate(argv[1], pip, 1);
	}
	close_unused_pipes(pip, num);
	duplicate_pipes(pip, num);
	pip->args = special_split(argv[arg_nr]);
	if (!pip->args)
		terminate("Invalid argument.", pip, 2);
	pip->cmd = test_cmd(pip->args[0], pip->spath);
	if (!pip->cmd)
		terminate(ft_strjoin(argv[arg_nr], ": command not found"), pip, 3);
	execve(pip->cmd, pip->args, envp);
	terminate(argv[arg_nr], pip, 1);
}

void	start_process(char **argv, char **envp, t_pipe *pip)
{
	int	i;

	pip->pids = malloc(pip->cmd_num * sizeof(pid_t));
	if (!pip->pids)
		terminate("Memory allocation failed.", pip, 1);
	i = 0;
	while (i < pip->cmd_num)
	{
		pip->pids[i] = fork();
		if (pip->pids[i] == 0)
			child(argv, envp, pip, i);
		i++;
	}
}
