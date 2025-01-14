/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:25:49 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/14 16:00:20 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "pipex.h"

int		ft_handle_first(char *argv[], char *envp[]);
int		ft_first_cmd(char *path, char **argv, char *filename);
int		ft_handle_mid(char *argv[], char *envp[], int r_end);
int		ft_mid_cmd(char *path, char *argv[], int r_end);
int		ft_handle_last(char *argv[], char *envp[], int r_end);
int		ft_last_cmd(char *path, char **argv, char *filename, int r_end);

#endif