/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_mid_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:23:33 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/14 16:09:09 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// handles a variable amount of times running command with pipes and pipes
// argc represents the amount of middle operations needed so with 5 elements
// argc would be 1
// when entering STDOUT is write_end of first pipe
// and STDIN is infile
// returns r_end of last used pipe
int	ft_handle_mid(char *argv[], char *envp[], int r_end)
{
	int		argc;
	int		pos;
	char	*path;
	char	**new_argv;

	argc = 0;
	pos = 0;
	while (argv[argc + 1] != NULL)
		argc++;
	argc -= 4;
	while (pos < argc)
	{
		path = ft_get_path(envp, argv[argc + 2]);
		if (path == NULL)
			return (-1);
		new_argv = ft_get_arg_for_execve(argv[argc + 2]);
		r_end = ft_mid_cmd(path, new_argv, r_end);
		free(path);
		ft_free_char_arr_arr(new_argv);
		if (r_end < 1)
			return (-1);
		pos++;
	}
	return (r_end);
}
