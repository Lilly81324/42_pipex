/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin_to_infile.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:13:26 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/13 15:13:40 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// opens a file by name in RD_ONLY
// redirects STDIN to that file
// closes the file itself directly
// returns -1 if error
int	ft_stdin_to_infile(char *filename)
{
	int	infile;

	infile = open(filename, O_RDONLY);
	if (infile < 0)
	{
		perror("Error opening infile");
		return (-1);
	}
	if (dup2(infile, STDIN_FILENO) < 0)
	{
		perror("Error redirecting stdin to infile");
		close(infile);
		return (-1);
	}
	close(infile);
	return (0);
}
