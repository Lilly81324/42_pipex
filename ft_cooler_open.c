/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cooler_open.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:11:23 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/14 18:56:44 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_cooler_open(char *filename)
{
	int		i;
	char	*copy;
	int		fd;

	i = 2;
	if (filename[0] == '/')
		fd = open(filename, O_RDWR);
	else if (ft_strchr(filename, '/') == NULL || (filename[0] == '.'
			&& filename[1] == '/'))
		fd = open(filename, O_RDWR);
	else
	{
		copy = (char *)malloc((ft_strlen(filename) + 3) * sizeof(char));
		copy[0] = '.';
		copy[1] = '/';
		while (filename[i - 2] != '\0')
		{
			copy[i] = filename[i - 2];
			i++;
		}
		copy[i] = '\0';
		fd = open(copy, O_RDWR);
		free(copy);
	}
	return (fd);
}
