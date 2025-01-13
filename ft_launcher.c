/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:09:14 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/13 15:30:49 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// prepares the ingredients for the execve call
int	ft_launcher(char *argv[], char *envp[])
{
	char	*path;
	char	**new_argv;
	int		r_end;

	path = ft_get_path(envp, argv[2]);
	if (path == NULL)
		return (-1);
	new_argv = ft_get_arg_for_execve(argv[2]);
	r_end = ft_prepare_first(path, new_argv, argv[1]);
	free(path);
	ft_free_char_arr_arr(new_argv);
	if (r_end < 1)
		return (-1);
	path = ft_get_path(envp, argv[3]);
	if (path == NULL)
		return (-1);
	new_argv = ft_get_arg_for_execve(argv[3]);
	ft_prepare_sec(path, new_argv, argv[4], r_end);
	free(path);
	ft_free_char_arr_arr(new_argv);
	if (r_end < 1)
		return (-1);
	return (0);
}
