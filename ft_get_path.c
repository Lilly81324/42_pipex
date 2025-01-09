/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:23:06 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/09 15:37:29 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// returns a string consisting of the PATH enviroment 
// variable given to the programm
static char	*ft_envp_path(char *const envp[])
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

// creates a name by writing <path + / + name>
// so <usr/bin/ls> into a string and returning it for use
static char	*ft_make_name(char *path, char *name)
{
	char	*full_path;

	full_path = (char *)calloc((ft_strlen(path) + ft_strlen(name) \
				+ 2), sizeof(char));
	ft_strlcpy(full_path, path, ft_strlen(path) + 1);
	ft_strlcpy(full_path + ft_strlen(full_path), "/", 2);
	ft_strlcpy(full_path + ft_strlen(full_path), name, ft_strlen(name) + 1);
	return (full_path);
}

// Checks wether a given Command "name" is found in any
// of the path variables from paths
// returns either the full path+command as string
// or NULL if error
// gives out error codes for file not found and/or no permission to execute
static char	*ft_check_access(char **paths, char *name)
{
	int		i;
	int		exists;
	int		acces;
	char	*full_path;

	i = 0;
	exists = -1;
	acces = -1;
	while (paths[i] != NULL)
	{
		full_path = ft_make_name(paths[i], name);
		if (exists == -1)
			exists = access(full_path, F_OK);
		acces = access(full_path, X_OK);
		if (exists == 0 && acces == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	if (exists != 0)
		perror("Command not found in PATH");
	if (exists == 0 && acces != 0)
		perror("No Permission to execute this command");
	return (NULL);
}

// Tries to find the path of the binary  of the given command
// from the enviroment pointer (PATHS) and returns
// the path with the file, so /usr/bin/ls
char	*ft_get_path(char **envp, char *cmd)
{
	char	**paths;
	char	*path;

	if (cmd == NULL)
	{
		perror("No Command specified");
		return (NULL);
	}
	cmd = ft_space_bef(cmd);
	paths = ft_split(ft_envp_path(envp), ':');
	path = ft_check_access(paths, cmd);
	free(cmd);
	ft_free_char_arr_arr(paths);
	return (path);
}
