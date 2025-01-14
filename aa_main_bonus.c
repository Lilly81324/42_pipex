/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aa_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:56:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/14 16:05:19 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// Right now it runs ls with the arguments givne to the programm
// So ./programm "/home" does what ls /home does
int	main(int argc, char *argv[], char *envp[])
{
	int	r_end;

	if (argc < 5)
	{
		perror("Need at least 4 arguments <infile> <cmd1> <cmd2> <outfile>");
		return (-1);
	}
	r_end = ft_handle_first(argv, envp);
	if (r_end < 0)
		return (-1);
	r_end = ft_handle_mid(argv, envp, r_end);
	if (r_end < 0)
		return (-1);
	r_end = ft_handle_last(argv, envp, r_end);
	if (r_end < 0)
		return (-1);
	return (0);
}

// r_end = ft_handle_mid(argv, envp, r_end);
// 	if (r_end < 0)
// 		return (-1);
// 	r_end = ft_handle_last(argv, envp, r_end);
// 	if (r_end < 0)
// 		return (-1);