/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:09:14 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/07 17:11:16 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// runs the commands
void	ft_launcher(int argc, char *argv[], char *envp[])
{
	char	*path;
	char	**new_argv;

	if (argc == 1)
	{
		printf("No Command specified\n");
		return ;
	}
	path = ft_get_path(envp, argv[2]);
	new_argv = ft_get_arg_for_execve(argv[2]);
	printf("FILE PATH=%s\n", path);
	printf("Arguments:%s, %s\n", new_argv[0], new_argv[1]);
	execve(path, new_argv, NULL);
	free(path);
	ft_free_char_arr_arr(new_argv);
}
