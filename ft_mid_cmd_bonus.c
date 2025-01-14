/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mid_cmd_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:18:23 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/14 15:18:25 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_mid_cmd(char *path, char *argv[], int r_end)
{
	pid_t	pid;

	if (ft_stdin_to_pipe(r_end) < 0)
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
