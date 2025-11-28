#include "../include/minishell.h"

int main(void)
{
    char *input;

    while (1)
    {
        input = readline("minishell> ");
        if (input == NULL)
        {
            printf("exit\n");
            break;
        }
        if (*input)
            add_history(input);
        free(input);
    }
    return (0);
}