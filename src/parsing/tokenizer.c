#include "../../include/minishell.h"

static char	*get_separator(char **input)
{
	char	*result;
	int		len;

	len = 1;
	if ((*input)[1] == (*input)[0])
		len++;
	result = ft_substr(*input, 0, len);
	*input += len;
	return (result);
}

char	*extract_token(char **input)
{
	char	*start;
	int		len;

	start = *input;
	if (**input && is_separator(**input))
		return (get_separator(input));
	len = 0;
	skip_word(*input, &len);
	*input += len;
	return (ft_substr(start, 0, len));
}

char	**tokenize_input(char *input)
{
	char	**tokens;
	int		count;
	int		i;

	if (!input)
		return (NULL);
	count = count_tokens(input);
	tokens = malloc(sizeof(char *) * (count + 1));
	if (!tokens)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*input && ft_isspace(*input))
			input++;
		tokens[i] = extract_token(&input);
		if (!tokens[i])
			return (NULL);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
