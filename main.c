/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaruso <ecaruso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:32:05 by ecaruso           #+#    #+#             */
/*   Updated: 2023/07/24 18:15:29 by ecaruso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror(char *str, int i, int *fd)
{
	perror(str);
	exit(i);
	if (fd)
		close(*fd);
}

int	ft_here_doc(int	*filein, char *limiter)
{
	char	*str;

	*filein = open("temp.txt", O_RDWR | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
	if (*filein == -1)
		ft_perror("Input open error", 3, filein);
	while ((ft_strncmp(str, limiter, ft_strlen(str) - 1)) || (
			ft_strlen(str) - 1) != ft_strlen(limiter))
	{
		write(1, &"pipe heredoc>", 13);
		str = get_next_line(0);
		if ((ft_strncmp(str, limiter, ft_strlen(str) - 1)) && write(
				*filein, str, ft_strlen(str)) == -1)
			ft_perror("Write error", 22, NULL);
		if (!str)
		{
			if (unlink("./temp.txt") != 0)
				ft_perror("unlink error", 21, NULL);
		}
		free(str);
	}
	close(*filein);
	*filein = open("temp.txt", O_RDONLY, 0777);
	return (*filein);
}

void	ft_setup(int argc, char **argv, t_utils *utils)
{
	if (utils->is_here_doc)
	{
		utils->i = 3;
		ft_here_doc(&utils->filein, argv[2]);
		utils->fileout = open(argv[
				argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		if (utils->fileout == -1)
			ft_perror("Output open error", 3, &utils->filein);
	}
	else
	{
		utils->i = 2;
		utils->filein = open(argv[1], O_RDONLY, 0777);
		if (utils->filein == -1)
			ft_perror("Input open error", 2, NULL);
		utils->fileout = open(argv[
				argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (utils->fileout == -1)
			ft_perror("Output open error", 3, &utils->filein);
	}
	ft_dup2(&utils->filein, STDIN_FILENO);
}

void	check_cmd(int argc, char **argv, char **env, t_utils *utils)
{
	int		j;
	char	**cmd;
	char	*path;

	j = utils->i;
	while (j <= argc - 2)
	{
		cmd = ft_split(argv[j++], ' ');
		path = get_path(cmd[0], env);
		if (!path)
		{
			close(utils->fileout);
			close(utils->filein);
			free_matrix(cmd);
			perror("Path Error");
			exit(20);
		}
		free_matrix(cmd);
		free(path);
	}
}

int	main(int argc, char **argv, char **env)
{
	int		test;
	t_utils	utils;

	if (argc == 1)
		exit(write(2, &"Not enough argoument\n", 21));
	utils.is_here_doc = !ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1]));
	if (argc < 5 || (utils.is_here_doc && argc != 6))
		exit(write(2, &"Argoument count not valid\n", 26));
	ft_setup(argc, argv, &utils);
	check_cmd(argc, argv, env, &utils);
	close(utils.filein);
	while (utils.i < argc -2)
		child_process(argv[utils.i++], env);
	if (utils.is_here_doc)
		unlink("temp.txt");
	test = fork();
	if (test == 0)
	{
		ft_dup2(&utils.fileout, STDOUT_FILENO);
		ft_execve(argv[utils.i], env);
	}
	waitpid(test, NULL, 0);
	close(utils.fileout);
}
