/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:45:38 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/10 13:50:50 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// should close pipe
int	ft_first_cmd(char *path, char **new_argv, int fd_in, int fd_out)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("Error creating fork");
		return (-1);
	}
	if (pid == 0)
	{
		execve(path, new_argv, NULL);
	}
}
