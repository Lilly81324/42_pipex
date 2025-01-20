/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_mid_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:23:33 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/20 18:18:32 by sikunne          ###   ########.fr       */
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
	pos = -1;
	while (argv[argc + 1] != NULL)
		argc++;
	argc -= 4;
	while (++pos < argc)
	{
		path = ft_get_path(envp, argv[pos + 3]);
		if (path == NULL)
			return (-1);
		new_argv = ft_split_quot_ex(argv[pos + 3], ' ');
		if (new_argv == NULL)
			return (-1);
		r_end = ft_mid_cmd(path, new_argv, r_end);
		free(path);
		ft_free_char_arr_arr(new_argv);
		if (r_end < 1)
			return (-1);
	}
	return (r_end);
}
