/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_sec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:53:30 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/20 15:46:53 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// prepares stdin and stdout for the first command
// then uses forking and waitpid to run the command
// frees path and argv given
// returns read_end fd of pipe (needs closing)
// returns -1 if error
int	ft_prepare_sec(char *path, char **argv, char *filename, int r_end)
{
	pid_t	pid;

	if (ft_stdin_to_pipe(r_end) || argv == NULL)
		return (-1);
	if (ft_stdout_to_outfile(filename) < 0)
		return (-1);
	pid = fork();
	if (pid < 0)
	{
		perror("Error creating fork\n");
		return (-1);
	}
	if (pid == 0)
		execve(path, argv, NULL);
	waitpid(pid, NULL, 0);
	return (0);
}
