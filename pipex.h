/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:42:19 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/09 16:30:32 by sikunne          ###   ########.fr       */
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
# include "./libft/ft_printf.h"
# include "./libft/get_next_line.h"

char	*ft_get_path(char **envp, char *cmd);
void	ft_free_char_arr_arr(char **target);
char	**ft_get_arg_for_execve(char *arg1);
char	*ft_space_bef(char *str);
char	*ft_space_aft(char *str);
void	ft_launcher(char *argv[], char *envp[]);
void	ft_first_cmd(char *path, char **new_argv, char *filename);
int		ft_first_cmd_pipe(char *path, char **new_argv);
void	ft_fork_one(int *pipe, char *path, char **argv);

#endif