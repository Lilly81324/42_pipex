/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aa_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:56:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/13 15:19:14 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Right now it runs ls with the arguments givne to the programm
// So ./programm "/home" does what ls /home does
int	main(int argc, char *argv[], char *envp[])
{
	if (argc < 5)
	{
		perror("Not enough arguments given");
		return (0);
	}
	return (ft_launcher(argv, envp));
}

/// need func(argv[2]/argv[3], from fd, to fd)
//	func(argv[2], infile_fd, pipe[1])
//	func(argv[2], pipe[0], outfile_fd)