/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:17:58 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/10 18:00:51 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_stdout_to_pipe(void)
{
	int	pipe_one[2];

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
	return (pipe_one[0]);
}

int	ft_stdin_to_infile(char *filename)
{
	int	infile;

	infile = open(filename, O_RDONLY);
	if (infile < 0)
	{
		perror("Error opening infile");
		return (-1);
	}
	if (dup2(infile, STDIN_FILENO) < 0)
	{
		perror("Error redirecting stdin to infile");
		close(infile);
		return (-1);
	}
	close(infile);
	return (0);
}

int	ft_prepare_first(char *path, char **argv, char *filename)
{
	pid_t	pid;
	int		r_end;

	if (ft_stdin_to_infile(filename) < 0)
		return (-1);
	r_end = ft_stdout_to_pipe();
	if (r_end < 0)
		return (-1);
	pid = fork();
	if (pid < 0)
	{
		perror("Error creating fork\n");
		return (-1);
	}
	if (pid == 0)
	{
		close(r_end);
		execve(path, argv, NULL);
	}
	waitpid(pid, NULL, 0);
	return (0);
}
