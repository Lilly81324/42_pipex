/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aa_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:56:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/07 17:08:36 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Right now it runs ls with the arguments givne to the programm
// So ./programm "/home" does what ls /home does
int	main(int argc, char *argv[], char *envp[])
{
	char	*path;
	char	**new_argv;

	if (argc == 1)
	{
		printf("No Command specified\n");
		return (0);
	}
	path = ft_get_path(envp, argv[2]);
	new_argv = ft_get_arg_for_execve(argv[2]);
	printf("FILE PATH=%s\n", path);
	printf("Arguments:%s, %s\n", new_argv[0], new_argv[1]);
	execve(path, new_argv, NULL);
	free(path);
	ft_free_char_arr_arr(new_argv);
	return (0);
}

// stdin would be redirected to infile
// int infile = open("infile", O_RDONLY);
// dup2(infile, STDIN_FILENO)
// close(infile); // infile is no longer needed after dup2
// ./pipex <input file name> <command with arguments> | -""-