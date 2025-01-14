/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_first_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:58:40 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/14 15:08:34 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// sets up the reading in of the first file as well as execution of first 
// command 
// returns r_end of pipe it wrote to
// returns -1 if error
int	ft_handle_first(char *argv[], char *envp[])
{
	char	*path;
	char	**new_argv;
	int		r_end;

	path = ft_get_path(envp, argv[2]);
	if (path == NULL)
		return (-1);
	new_argv = ft_get_arg_for_execve(argv[2]);
	r_end = ft_first_cmd(path, new_argv, argv[1]);
	free(path);
	ft_free_char_arr_arr(new_argv);
	if (r_end < 1)
		return (-1);
	return (r_end);
}
