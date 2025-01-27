/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aa_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:56:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/27 15:40:32 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Runs two shell commands with custom input and output 
// Usage ./pipex <infile> <cmd1> <cmd2> <outfile>
// Uses the contents of the "infile" (first argument) as input
// for the shell command "cmd1" (second argument) which gives its output
// as input for the second command "cmd2" (third argument) which gives
// its output into the "outfile" (fourth argument) by overwriting from start
int	main(int argc, char *argv[], char *envp[])
{
	int	r_end;

	if (argc < 5)
	{
		perror("Need 4 arguments <infile> <cmd1> <cmd2> <outfile>");
		return (-1);
	}
	if (argc > 5)
	{
		perror("Too many arguments, only 4 are acceptable");
		return (-1);
	}
	ft_stdout_to_outfile(argv[argc - 1], envp);
	r_end = ft_handle_first(argv, envp);
	if (r_end < 0)
		return (-1);
	r_end = ft_handle_last(argv, envp, r_end);
	if (r_end < 0)
		return (-1);
	return (0);
}
