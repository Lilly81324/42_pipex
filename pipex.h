/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:42:19 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/21 15:05:50 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "./libft/libft.h"

// for setup of commands
char	*ft_get_path(char **envp, char *cmd);
void	ft_free_char_arr_arr(char **target);
char	*ft_space_bef(char *str);
char	*ft_space_aft(char *str);
int		ft_cooler_open(char *filename);
char	**ft_split_quot_ex(char const *s, char c);

// redirection of stdin and stdout
int		ft_stdin_to_infile(char *filename);
int		ft_stdin_to_pipe(int r_end);
int		ft_stdout_to_outfile(char *filename);
int		ft_stdout_to_pipe(void);

// for running the commands each (ft_handle_X calls ft_X_cmd)
int		ft_handle_first(char *argv[], char *envp[]);
int		ft_first_cmd(char *path, char **argv, char *filename);
int		ft_handle_last(char *argv[], char *envp[], int r_end);
int		ft_last_cmd(char *path, char **argv, char *filename, int r_end);

#endif