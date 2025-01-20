/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_cmd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:03:26 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/14 15:51:01 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// prepares stdin and stdout for the first command
// then uses forking and waitpid to run the command
// frees path and argv given
// returns read_end fd of pipe (needs closing)
// returns -1 if error
int	ft_first_cmd(char *path, char **argv, char *filename)
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
	return (r_end);
}
