/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaruso <ecaruso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:17:00 by ecaruso           #+#    #+#             */
/*   Updated: 2023/07/24 17:03:38 by ecaruso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char *str, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
	{
		close (fd[0]);
		ft_dup2(&fd[1], STDOUT_FILENO);
		close (fd[1]);
		ft_execve(str, env);
	}
	else
	{
		close(fd[1]);
		ft_dup2(&fd[0], STDIN_FILENO);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
}
