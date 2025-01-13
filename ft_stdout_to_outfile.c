/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdout_to_outfile.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:14:22 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/13 15:14:24 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// opens a file by name in RDWR
// redirects STDOUT to that file
// closes the file itself directly
// returns -1 if error
int	ft_stdout_to_outfile(char *filename)
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
		perror("Error redirecting stdout to outfile");
		close(outfile);
		return (-1);
	}
	close(outfile);
	return (0);
}
