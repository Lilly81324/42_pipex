/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_cmd_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:39:33 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/10 13:53:38 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_first_cmd_pipe(char *path, char **new_argv)
{
	int		pipe_one[2];
	int		stdout_copy;

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
	return (pipe_one[0]);
}
