#include "shell.h"

ssize_t get_input(char **line, size_t *count)
{
    return getline(line, count, stdin);
}

char **tokenize_input(char *line, const char *delimiter)
{
    char *token;
    int i;
    int token_count = 0;
    char **tokens = NULL;

    for (i = 0, token = strtok(line, delimiter); token != NULL; i++)
    {
        token_count++;
        token = strtok(NULL, delimiter);
    }
    token_count++;

    tokens = malloc(sizeof(char *) * token_count);

    for (i = 0, token = strtok(line, delimiter); token != NULL; i++)
    {
        tokens[i] = strdup(token);
        vour_print("%s\n", tokens[i]);
        token = strtok(NULL, delimiter);
    }

    return tokens;
}