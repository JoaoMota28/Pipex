/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:17:57 by jomanuel          #+#    #+#             */
/*   Updated: 2025/02/28 11:05:06 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef struct s_pipe
{
	pid_t	*pids;
	int		fd_in;
	int		fd_out;
	int		cmd_num;
	int		**pipes;
	char	*path;
	char	*cmd;
	char	**spath;
	char	**args;
	int		heredoc;
}	t_pipe;

void	path(t_pipe *pip, char **envp);
char	*test_cmd(char *arg, char **spath);
void	init_pip(t_pipe *pip);
void	free_all(t_pipe *pip);
void	terminate(char *msg, t_pipe *pip, int flag);
char	**special_split(const char *s);
void	start_process(char **argv, char **envp, t_pipe *pip);
void	child(char **argv, char **envp, t_pipe *pip, int num);
void	open_in(char **argv, t_pipe *pip);
void	open_out(int argc, char **argv, t_pipe *pip);
void	heredoc(char **argv, t_pipe *pip);
void	open_pipes(t_pipe *pip);
void	duplicate_pipes(t_pipe *pip, int num);
void	close_unused_pipes(t_pipe *pip, int num);
void	close_all_pipes(t_pipe *pip);

#endif
