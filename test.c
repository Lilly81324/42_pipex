#include <stdio.h>
#include <stdlib.h>

int	move_until(char *s, int	i, char	opt)
{
	i++;
	while (s[i] != opt && s[i] != '\0')
		i++;
	if (s[i] == '\0')
	{
		perror("Error, quotation mark not closed properly");
		return (-1);
	}
	else
		i++;
	return (i);
}

// returns how many "words" are in a string
int	get_sets(char *s, char c)
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

int main(int argc, char *argv[])
{
	int		i;
	char	*str;

	if (argc == 1)
		return (0);
	i = get_sets(argv[1], ' ');
	return (0);
}
