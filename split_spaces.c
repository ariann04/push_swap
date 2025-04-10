#include "push_swap.h"

int	whitespace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	count_words(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (whitespace(str[i]))
			i++;
		while (str[i])
			count++;
		while (str[i] && !whitespace(str[i]))
			i++;
	}
	return (count);
}

char	*get_next_word(char *str)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && !whitespace(str[i]))
		i++;
	word = malloc(sizeof(char *) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && !whitespace(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**split_spaces(char	*str)
{
	char	**result;
	int		num_words;
	int		i;

	num_words = count_words(str);
	result = malloc(sizeof(char *) * num_words + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < num_words)
	{
		while (whitespace(*str))
			str++;
		result[i] = get_next_word(str);
		if (!result[i])
		{
			free_array(result);
			return (NULL);
		}
		while (*str && !whitespace(*str))
			str++;
	}
	result[i] = NULL;
	return (result);
}
