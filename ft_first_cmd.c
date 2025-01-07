/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:17:53 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/07 17:32:14 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_first_cmd(char *path, char **new_argv, char *filename)
{
	int	infile;

	infile = open(filename, O_RDONLY);
	if (infile < 0)
	{
		perror("Error opening infile");
		return ;
	}
	if (dup2(infile, STDIN_FILENO) < 0)
	{
		perror("Error redirecting stdin to infile");
		close(infile);
		return ;
	}
	close(infile);
	execve(path, new_argv, NULL);
}
