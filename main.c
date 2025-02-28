/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:23:59 by jomanuel          #+#    #+#             */
/*   Updated: 2025/02/28 12:34:19 by jomanuel         ###   ########.fr       */
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
	if (argc == 5)
	{
		open_in(argv, &pip);
		open_out(argc, argv, &pip);
		pip.cmd_num = argc - 3 - pip.heredoc;
		open_pipes(&pip);
		start_process(argv, envp, &pip);
		close_all_pipes(&pip);
		while (++i < pip.cmd_num)
			waitpid(pip.pids[i], NULL, 0);
		free_all(&pip);
	}
	else
		ft_putendl_fd("Invalid number of arguments.", 2);
	return (0);
}
