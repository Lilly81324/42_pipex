/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_split2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:18:46 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/15 19:18:46 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	toggle(int num)
{
	if (num == 0)
		return (1);
	else
		return (0);
}

// This function counts how many blocks of..
// ..text are delimited by start of string, the character..
// ..water or the end of file. It returns that number
static int	ft_st_get_sets2(char const *sea, char water)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i)
	{
		while (sea[i] == water && sea[i] != '\0')
			i++;
		if (sea[i] != water)
		
		if (sea[i] == '\'')
		{
			i++;
			while (sea[i] != '\0' && sea[i] != '\'')
				i++;
		}
		if (sea[i] == '\"')
		{
			i++;
			while (sea[i] != '\0' && sea[i] != '\"')
				i++;
		}
	}
	return (counter);
}
