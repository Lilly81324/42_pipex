/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aa_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:56:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/03 17:43:08 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	int		fd;
	char	*str;
	char	*str2;

	fd = open("test.txt", O_RDONLY);
	str = (char *)ft_calloc(4, sizeof(char));
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str2 = get_next_line(fd);
	ft_printf("working %i\n", ft_strlen(str));
	ft_printf("-%s-\n", str2);
	free(str2);
	return (0);
}
