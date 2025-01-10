/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scnd_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:56:22 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/10 15:19:27 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_scnd_cmd(char *path, char **new_argv, char *filename, int r_end)
{
	int	outfile;

	outfile = open(filename, O_RDWR);
	if (outfile < 0)
	{
		perror("Error opening outfile");
		return (-1);
	}
	if (dup2(outfile, STDOUT_FILENO) < 0)
	{
		perror("Error redirecting stdin to infile");
		close(outfile);
		return (-1);
	}
	close(outfile);
	if (dup2(r_end, STDIN_FILENO) < 0)
	{
		perror("Error redirecting read end to stdin");
		close(r_end);
		return (-1);
	}
	close(r_end);
	if (ft_fork_two(path, new_argv) == -1)
		return (-1);
	printf("Working\n");
	return (0);
}
