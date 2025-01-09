/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:36:53 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/09 17:05:49 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int	main(void)
{
	int		pipe_one[2];
	pid_t	pid;
	char	string[10] = "123456789";
	int		status;
	char	buf[6];

	pipe(pipe_one);
	dup2(pipe_one[1], STDOUT_FILENO);
	pid = fork();
	close(pipe_one[1]);
	if (pid == 0)
	{
		printf("%s\n", string);
		perror("wrote");
		close(pipe_one[0]);
		return (1);
	}
	waitpid(pid, NULL, 0);
	read(pipe_one[0], buf, 4);
	buf[5] = '\0';
	dup2(0, STDOUT_FILENO);
	printf("-%s-\n", buf);
	return (1);
}
