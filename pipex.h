/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaruso <ecaruso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:33:06 by ecaruso           #+#    #+#             */
/*   Updated: 2023/07/24 17:47:13 by ecaruso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_utils
{
	int	i;
	int	is_here_doc;
	int	filein;
	int	fileout;
}	t_utils;

void	child_process(char *str, char **env);
void	free_matrix(char **matrix);
void	ft_dup2(int	*fd, int arg);
char	*get_next_line(int fd);
char	*get_path(char *cmd, char **env);
char	*ft_gnl_strchr(char *s, int c);
char	*ft_gnl_strjoin(char *backup, char *buff);
char	*ft_get_line(char *backup);
char	*ft_backup(char *backup);

#endif