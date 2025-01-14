/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_last_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:09:44 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/14 15:12:43 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_handle_last(char *argv[], char *envp[], int r_end)
{
	char	*path;
	char	**new_argv;

	path = ft_get_path(envp, argv[3]);
	if (path == NULL)
		return (-1);
	new_argv = ft_get_arg_for_execve(argv[3]);
	r_end = ft_last_cmd(path, new_argv, argv[4], r_end);
	free(path);
	ft_free_char_arr_arr(new_argv);
	if (r_end < 1)
		return (-1);
	return (r_end);
}
