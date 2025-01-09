/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:23:52 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/09 18:01:31 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_fork_one(int *pipe, char *path, char **argv)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
	{
		perror("Error creating fork\n");
		close(pipe[0]);
		close(pipe[1]);
		return ;
	}
	if (pid == 0)
	{
		close(pipe[0]);
		execve(path, argv, NULL);
	}
	waitpid(pid, &status, 0);
}
