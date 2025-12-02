#include "../../include/minishell.h"

void	print_syntax_error(char *token)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	ft_putstr_fd(token, 2);
	ft_putstr_fd("'\n", 2);
}

static int	is_invalid_pipe(char **tokens, int i)
{
	if (!tokens[i + 1] || ft_strncmp(tokens[i + 1], "|", 2) == 0)
	{
		print_syntax_error("|");
		return (1);
	}
	return (0);
}

static int	is_invalid_redir(char **tokens, int i)
{
	if (!tokens[i + 1])
	{
		print_syntax_error("newline");
		return (1);
	}
	if (ft_strncmp(tokens[i + 1], "|", 1) == 0
		|| ft_strncmp(tokens[i + 1], "<", 1) == 0
		|| ft_strncmp(tokens[i + 1], ">", 1) == 0)
	{
		print_syntax_error(tokens[i + 1]);
		return (1);
	}
	return (0);
}

int	check_syntax(char **tokens)
{
	int	i;

	if (tokens[0] && ft_strncmp(tokens[0], "|", 2) == 0)
	{
		print_syntax_error("|");
		return (1);
	}
	i = 0;
	while (tokens[i])
	{
		if (ft_strncmp(tokens[i], "|", 2) == 0)
		{
			if (is_invalid_pipe(tokens, i))
				return (1);
		}
		else if (ft_strncmp(tokens[i], "<", 1) == 0
			|| ft_strncmp(tokens[i], ">", 1) == 0)
		{
			if (is_invalid_redir(tokens, i))
				return (1);
		}
		i++;
	}
	return (0);
}
