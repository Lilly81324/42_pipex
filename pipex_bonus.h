/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:25:49 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/21 15:08:15 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "pipex.h"

// handles the middle commands
int		ft_handle_mid(char *argv[], char *envp[], int r_end);
int		ft_mid_cmd(char *path, char *argv[], int r_end);

#endif