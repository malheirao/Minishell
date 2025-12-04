#include "../../include/minishell.h"

int	is_separator(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

void	skip_quoted(char *input, int *i)
{
	char	quote;

	quote = input[(*i)++];
	while (input[*i] && input[*i] != quote)
		(*i)++;
	if (input[*i])
		(*i)++;
}

void	skip_word(char *input, int *i)
{
	while (input[*i] && !ft_isspace(input[*i]) && !is_separator(input[*i]))
	{
		if (input[*i] == '\'' || input[*i] == '"')
			skip_quoted(input, i);
		else
			(*i)++;
	}
}

int	count_tokens(char *input)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (input[i])
	{
		while (input[i] && ft_isspace(input[i]))
			i++;
		if (input[i])
			count++;
		if (input[i] && is_separator(input[i]))
		{
			if (input[i + 1] == input[i])
				i++;
			i++;
			continue ;
		}
		skip_word(input, &i);
	}
	return (count);
}

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}
