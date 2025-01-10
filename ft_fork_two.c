/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:23:52 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/10 15:29:38 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_fork_two(char *path, char **argv)
{
	pid_t	pid;
	int		status;

	pid = fork();
	printf("pid\n");
	if (pid < 0)
	{
		perror("Error creating fork\n");
		return (-1);
	}
	if (pid == 0)
	{
		printf("child\n");
		execve(path, argv, NULL);
	}
	waitpid(pid, &status, 0);
	printf("parent\n");
	return (0);
}
