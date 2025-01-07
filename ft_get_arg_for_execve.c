/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_for_execve.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:40:45 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/07 17:06:08 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// creates argv for execve functions to run
// this consists of an array of strings
// [0] being the new programm name
// [1] being the argument for the new programm or NULL
// [2] being NULL to mark END
char	**ft_get_arg_for_execve(char *arg1)
{
	char	**result;

	result = (char **)malloc(3 * sizeof(char *));
	result[0] = ft_space_bef(arg1);
	result[1] = ft_space_aft(arg1);
	result[2] = NULL;
	return (result);
}
