#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../LIBFT/libft.h"

typedef struct s_command
{
    char                **args;
    int                 fd_in;
    int                 fd_out;
    struct s_command    *next;
}   t_command;

// Syntax Check
int         check_syntax(char **tokens);
void        print_syntax_error(char *token);

// Utils
int         ft_isspace(char c);

#endif