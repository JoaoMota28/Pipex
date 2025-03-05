/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:37:00 by jomanuel          #+#    #+#             */
/*   Updated: 2025/03/05 11:19:44 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*retireve_path(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

void	path(t_pipe *pip, char **envp)
{
	pip->path = retireve_path(envp);
	if (!pip->path)
		exit(1);
	pip->spath = ft_split(pip->path, ':');
}

char	*test_cmd(char *arg, char **spath)
{
	char	*tmp;
	char	*cmd;
	int		i;

	tmp = NULL;
	cmd = NULL;
	i = 0;
	if (access(arg, X_OK) == 0)
		return (arg);
	cmd = ft_strjoin("./", arg);
	if (access(cmd, X_OK) == 0)
		return (cmd);
	free(cmd);
	while (spath[i])
	{
		tmp = ft_strjoin(spath[i], "/");
		cmd = ft_strjoin(tmp, arg);
		free(tmp);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		free(cmd);
		i++;
	}
	return (NULL);
}
