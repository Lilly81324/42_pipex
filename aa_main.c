/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aa_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:56:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/08 17:12:24 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Right now it runs ls with the arguments givne to the programm
// So ./programm "/home" does what ls /home does
int	main(int argc, char *argv[], char *envp[])
{
	if (argc == 1)
	{
		printf("No Command specified\n");
		return (0);
	}
	ft_launcher(argv, envp);
	return (0);
}

// Right now we have infile in stdin
// then we execute a execve process.
// that process uses stdin and outputs to stdout

// we have to redirect stdout to stdin of another process
// that we do through piping
// in the new process we set stdout to some filedescriptor in write mode
// the new process is ran with execve

// do we need fork?
// 