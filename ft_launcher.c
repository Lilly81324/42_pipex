/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:09:14 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/10 14:10:56 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// prepares the ingredients for the execve call
void	ft_launcher(char *argv[], char *envp[])
{
	char	*path;
	char	**new_argv;
	int		r_end;

	path = ft_get_path(envp, argv[2]);
	new_argv = ft_get_arg_for_execve(argv[2]);
	printf("FILE PATH=%s\n", path);
	printf("Arguments:%s, %s\n", new_argv[0], new_argv[1]);
	r_end = ft_first_cmd(path, new_argv, argv[1]);
	path = ft_get_path(envp, argv[3]);
	new_argv = ft_get_arg_for_execve(argv[3]);
	ft_scnd_cmd(path, new_argv, argv[4], r_end);
	free(path);
	ft_free_char_arr_arr(new_argv);
}
