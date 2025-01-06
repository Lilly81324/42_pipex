/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aa_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:56:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/06 18:06:10 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// returns a string consisting of the PATH enviroment 
// variable given to the programm
char	*ft_get_path(char *const envp[])
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		i;
	char	**paths;
	char	*path;

	if (argc == 1)
	{
		printf("No Command specified");
		return (0);
	}
	i = 0;
	paths = ft_split(ft_get_path(envp), ':');
	path = ft_check_access(paths, "ls");
	ft_free_char_arr_arr(paths);
	if (path == NULL)
		return (0);
	printf("FILE PATH=%s\n", path);
	execve(path, argv, NULL);
	free(path);
	return (0);
}
