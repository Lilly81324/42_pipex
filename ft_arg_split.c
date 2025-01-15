/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:49:16 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/15 17:18:14 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// if you encounter a " toggle quotes
// if you encounter a space, but quotes
//		i++;
// if you encounter a space and quotes is 0
// counter 
// make new string

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
	int	quotes;
	int	d_quotes;

	i = 0;
	counter = 0;
	quotes = 0;
	d_quotes = 0;
	if (sea == NULL)
		return (0);
	while (sea[i] != '\0')
	{
		// if land and no quotes
		if (sea[i] != water && quotes == 0 && d_quotes == 0)
			counter++;
		// assume land is here
		while (sea[i] != water && sea[i] != '\0')
		{
			if (sea[i] == '\"')
				d_quotes = toggle(d_quotes);
			if (sea[i] == '\'')
				quotes = toggle(quotes);
			i++;
		}
		// land is over
		while (sea[i] == water && sea[i] != '\0')
		{
			if (sea[i] == '\"')
				d_quotes = toggle(d_quotes);
			if (sea[i] == '\'')
				quotes = toggle(quotes);
			i++;
		}
	}
	return (counter);
}

// This function is only called when a block..
// ..of text is supposed to be made into a substring.
// It returns the position where that block ends or..
// ..-1 if Allocation failed
static int	ft_st_splitter(char const *s, char c, int pos, char **result)
{
	int	arrpos;
	int	size;

	arrpos = 0;
	size = 0;
	while (s[pos + size] != c && s[pos + size] != '\0')
		size++;
	while (result[arrpos] != NULL)
		arrpos++;
	result[arrpos] = (char *)malloc((size + 1) * sizeof(char));
	if (result[arrpos] == NULL)
		return (-1);
	size = 0;
	while (s[pos] != c && s[pos] != '\0')
	{
		result[arrpos][size] = s[pos];
		size++;
		pos++;
	}
	result[arrpos][size] = '\0';
	return (pos);
}

// This function is called, when allocating...
// ...a string failed. It frees all strings up to..
// ...that one, frees result and returns a NULL
static char	**ft_st_free_result(char **result, int count)
{
	int	i;

	i = 0;
	while (i < count && result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

// This function is the central function, it uses...
// ...the other functions to split a string into...
// smaller strings and returns that array of arrays
char	**ft_split(char const *s, char c)
{
	int		pos;
	int		count;
	char	**result;

	pos = -1;
	if (s == NULL)
		return (NULL);
	count = ft_st_get_sets(s, c);
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (++pos < count + 1)
		result[pos] = NULL;
	pos = 0;
	while (s[pos] != '\0')
	{
		if (s[pos] != c)
			pos = ft_st_splitter(s, c, pos, result);
		if (pos == -1)
			return (ft_st_free_result(result, count));
		while (s[pos] == c && s[pos] != '\0')
			pos++;
	}
	return (result);
}

int main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	printf("%i\n", ft_st_get_sets2(argv[1], ' '));
	return (0);
}
