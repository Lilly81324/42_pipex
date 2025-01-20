/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:17:58 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/20 15:46:33 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// prepares stdin and stdout for the first command
// then uses forking and waitpid to run the command
// frees path and argv given
// returns read_end fd of pipe (needs closing)
// returns -1 if error
int	ft_prepare_first(char *path, char **argv, char *filename)
{
	pid_t	pid;
	int		r_end;

	if (ft_stdin_to_infile(filename) < 0 || argv == NULL)
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
