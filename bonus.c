/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:07:39 by jomanuel          #+#    #+#             */
/*   Updated: 2025/03/09 23:21:47 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pip;
	int		i;

	i = -1;
	init_pip(&pip);
	path(&pip, envp);
	if (argv[1] && !ft_strncmp(argv[1], "here_doc", 9))
		pip.heredoc = 1;
	if (argc >= (5 + pip.heredoc))
	{
		open_in(argv, &pip);
		open_out(argc, argv, &pip);
		pip.cmd_num = argc - 3 - pip.heredoc;
		open_pipes(&pip);
		start_process(argv, envp, &pip);
		close_all_pipes(&pip);
		while (++i < pip.cmd_num)
			waitpid(pip.pids[i], NULL, 0);
	}
	else
		ft_putendl_fd("Invalid number of arguments.", 2);
	free_all(&pip);
	return (0);
}
