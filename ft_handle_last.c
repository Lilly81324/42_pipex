/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:09:44 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/21 15:01:45 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// same thing as ft_handle_first, but for the last
// command, which gets written into an outfile instead of a pipe
// returns 0 if norminal or -1 if error
int	ft_handle_last(char *argv[], char *envp[], int r_end)
{
	char	*path;
	char	**new_argv;
	int		ind_end;

	ind_end = 0;
	while (argv[ind_end] != NULL)
		ind_end++;
	ind_end--;
	path = ft_get_path(envp, argv[ind_end - 1]);
	if (path == NULL)
		return (-1);
	new_argv = ft_split_quot_ex(argv[ind_end - 1], ' ');
	if (new_argv == NULL)
		return (-1);
	r_end = ft_last_cmd(path, new_argv, argv[ind_end], r_end);
	free(path);
	ft_free_char_arr_arr(new_argv);
	if (r_end < 1)
		return (-1);
	return (r_end);
}
