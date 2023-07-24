/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaruso <ecaruso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:17:00 by ecaruso           #+#    #+#             */
/*   Updated: 2023/07/24 17:24:10 by ecaruso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix [++i])
		free(matrix[i]);
	free(matrix);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*temp;
	char	*path;
	char	**base;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5))
		i++;
	base = ft_split((env[i] + 5), ':');
	i = -1;
	while (base && base[++i])
	{
		temp = ft_strjoin(base[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, X_OK) == 0)
		{
			free_matrix(base);
			return(path);
		}
		free(path);
	}
	free_matrix(base);
	return (NULL);
}

void	ft_dup2(int	*fd, int arg)
{
	if (dup2(*fd, arg) == -1)
		exit(1);
	close(*fd);
}

void	ft_execve(char *str, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(str, ' ');
	path = get_path(cmd[0], env);
	if (!path)
	{
		free_matrix(cmd);
		perror("Path Error");
		exit(20);
	}
	if (execve(path, cmd, env) == -1)
	{
		perror("Command Error");
		exit(30);
	}
}

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
