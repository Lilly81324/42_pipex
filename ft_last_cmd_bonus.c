/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_cmd_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:13:07 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/14 16:00:01 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// prepares stdin and stdout for the first command
// then uses forking and waitpid to run the command
// frees path and argv given
// returns read_end fd of pipe (needs closing)
// returns -1 if error
int	ft_last_cmd(char *path, char **argv, char *filename, int r_end)
{
	pid_t	pid;

	if (ft_stdin_to_pipe(r_end))
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
