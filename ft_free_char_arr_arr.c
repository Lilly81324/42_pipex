/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_arr_arr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:02:09 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/06 17:58:17 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// properly frees an array of arrays of characters
// the older brother of ft_split
void	ft_free_char_arr_arr(char **target)
{
	int	i;

	i = 0;
	if (target == NULL)
		return ;
	while (target[i] != NULL)
	{
		free(target[i]);
		target[i] = NULL;
		i++;
	}
	free(target);
	target = NULL;
}
