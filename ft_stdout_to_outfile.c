/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdout_to_outfile.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:14:22 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/22 15:43:05 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// creates a file via touch wherever the name places it
static void	ft_touch_file(char *name, char *envp[])
{
	char	*path;
	char	*argv[3];
	int		i;
	pid_t	pid;

	i = -1;
	path = ft_get_path(envp, "touch");
	argv[0] = "touch";
	argv[1] = name;
	argv[2] = NULL;
	pid = fork();
	if (pid < 0)
	{
		perror("Error creating fork\n");
		return ;
	}
	if (pid == 0)
		execve(path, argv, NULL);
	free(path);
	waitpid(pid, NULL, 0);
}

// Checks wether a certain file exists, andd can be accesed
// doesnt exits returns -1
// no permission returns 0
// valid permission returns 1
static int	ft_check_file(char *name, char *envp[])
{
	int		exists;
	int		acces;

	exists = access(name, F_OK);
	acces = access(name, W_OK);
	if (exists == 0 && acces == 0)
		return (1);
	if (exists != 0)
	{
		ft_touch_file(name, envp);
		return (-1);
	}
	perror("No Permission to open outfile");
	return (0);
}

// opens a file by name in RDWR
// redirects STDOUT to that file
// closes the file itself directly
// returns -1 if error
int	ft_stdout_to_outfile(char *filename, char *envp[])
{
	int	outfile;

	if (ft_check_file(filename, envp) == 0)
		return (-1);
	outfile = ft_cooler_open(filename);
	if (outfile < 0)
	{
		perror("Error opening outfile");
		return (-1);
	}
	if (dup2(outfile, STDOUT_FILENO) < 0)
	{
		perror("Error redirecting stdout to outfile");
		close(outfile);
		return (-1);
	}
	close(outfile);
	return (0);
}
