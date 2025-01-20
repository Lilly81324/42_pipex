/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:49:16 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/20 03:00:29 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// moves until it reaches end or opt
// returns the index of that character
// returns -1 if character not found
int	move_until(char const *s, int	i, char	opt)
{
	ft_printf("Called at %i", i);
	i++;
	while (s[i] != opt && s[i] != '\0')
	{
		ft_printf("%c\n", s[i]);
		i++;
	}
	if (s[i] == '\0')
	{
		perror("Error, quotation mark not closed properly");
		return (-1);
	}
	return (i);
}

// returns how many "words" are in a string
// returns -1 if error
int	get_sets(char const *s, char c)
{
	int		i;
	int		strings;

	i = 0;
	strings = 0;
	while(s[i] != '\0')
	{
		while(s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
			strings++;
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
			if (s[i - 1] == '\'')
				i = move_until(s, i, '\'');
			else if (s[i - 1] == '\"')
				i = move_until(s, i, '\"');
			if (i < 0)
				return (-1);
		}
	}
	return (strings);
}

// This function is called, when allocating...
// ...a string failed. It frees all strings up to..
// ...that one, frees result and returns a NULL
static char	**free_result(char **result)
{
	int	i;

	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

// called at the first character of a string
// gives back the string, or NULL if error
// sets i to the index of the first occurence of c after that string
char	*get_string(char const *s, int *i, char c)
{
	int		start;
	char	*str;
	int		j;

	start = *i;
	j = 0;
	while (s[*i] != '\0' && s[*i] != c)
	{
		(*i)++;
		if (s[(*i) - 1] == '\'')
			*i = move_until(s, *i, '\'');
		else if (s[(*i) - 1] == '\"')
			*i = move_until(s, *i, '\"');
		if (*i < 0)
			return (NULL);
	}
	str = (char *)malloc((((*i) - start) + 1) * sizeof(char));
	while (j < ((*i) - start))
	{
		str[j] = s[start + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

// turns a source string into seperate strings containing each "word"
// a "word" is defined as being between the char c, start of string
// or end of string
// compared to ft_split, this function properly handles quotes
// returns -1 if error
int	ft_splitter(char const *s, char c, char **result)
{
	int	arrpos;
	int	i;

	arrpos = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			result[arrpos] = get_string(s, &i, c);
			if (result[arrpos] == NULL)
				return (-1);
			arrpos++;
		}
	}
	result[arrpos] = NULL;
	return (0);
}

// This function is the central function, it uses...
// ...the other functions to split a string into...
// smaller strings and returns that array of arrays
char	**ft_split_quot(char const *s, char c)
{
	int		count;
	char	**result;

	count = get_sets(s, c);
	if (count < 1)
		return (NULL);
	ft_printf("%i words\n", count);
	result = (char **)malloc((count + 1) * sizeof(int *));
	count = ft_splitter(s, c, result);
	if (count < 0)
		return (free_result(result));
	return (result);
}

int main(int argc, char *argv[])
{
	int	i;
	char **result;
	
	if (argc == 1)
		return (0);
	i = 0;
	result = ft_split_quot(argv[1], ' ');
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		i++;
	}
	free_result(result);
	return (0);
}
