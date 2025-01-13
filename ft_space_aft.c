/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_aft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:41:11 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/13 15:21:23 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// returns a string consisting of the contents after the
// first occurence of ' ' in the given string
char	*ft_space_aft(char *str)
{
	int		bef;
	int		aft;
	char	*new_str;

	bef = 0;
	aft = 0;
	if (str == NULL)
		return (NULL);
	while (str[bef] != '\0' && str[bef] != ' ')
		bef++;
	if (str[bef] == ' ')
		bef++;
	while (str[bef + aft] != '\0' && str[bef + aft] != ' ')
		aft++;
	if (aft == 0)
		return (NULL);
	new_str = (char *)malloc((aft + 1) * sizeof(char));
	aft = 0;
	while (str[bef + aft] != '\0' && str[bef + aft] != ' ')
	{
		new_str[aft] = str[bef + aft];
		aft++;
	}
	new_str[aft] = '\0';
	return (new_str);
}
