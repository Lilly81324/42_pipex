/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:17:53 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/09 17:38:29 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// redirect stdin for first command to filename
// then run the pipe redirection
void	ft_first_cmd(char *path, char **new_argv, char *filename)
{
	int	infile;
	int	pipe_r_end;

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
	pipe_r_end = ft_first_cmd_pipe(path, new_argv);
	close(pipe_r_end);
}
