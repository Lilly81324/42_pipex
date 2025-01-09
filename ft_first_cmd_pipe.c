/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_cmd_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:39:33 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/09 18:32:38 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_first_cmd_pipe(char *path, char **new_argv)
{
	int		pipe_one[2];
	char	buff[200];
	int		stdout_copy;
	size_t	bytes;

	stdout_copy = dup(STDOUT_FILENO);
	if (pipe(pipe_one) == -1)
	{
		perror("Error creating pipe\n");
		return (-1);
	}
	if (dup2(pipe_one[1], STDOUT_FILENO) < 0)
	{
		perror("Error redirecting stdout to write end of pipe\n");
		close(pipe_one[0]);
		close(pipe_one[1]);
		return (-1);
	}
	close(pipe_one[1]);
	ft_fork_one(pipe_one, path, new_argv);
	write(STDOUT_FILENO, "\0", 1);
	bytes = read(pipe_one[0], buff, 150);
	close(pipe_one[0]);
	if (dup2(stdout_copy, STDOUT_FILENO) < 0)
	{
		perror("didnt redirect back");
		return (0);
	}
	printf("-%s-\n", buff);
	printf("read: %zu bytes\n", bytes);
	return (pipe_one[0]);
}
