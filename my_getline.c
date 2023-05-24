#include "main.h"
/**
 * _getline - work the same way as the getline function.
 * @line: where we want ot store what we read from the user.
 * @stm: the stream where data is sent to and read.
 * Return: -1 in case of failure and number of bytes if
 * everything is working as expected.
*/
ssize_t _getstr(char **line, int stm)
{
    ssize_t nb_bytes_read, count_nb_bytes_read = 0;
    size_t length = 0;
    char character;
    size_t s = sizeof(char);
    char *stdin_line = malloc(sizeof(char) + 2);

    if (stdin_line == NULL)
        return (-1);
    while ((nb_bytes_read = read(stm, &character, 1)) > 0)
    {
        if (character != '\n')
        {
            if (length < s)
            {
                stdin_line[length++] = character;
                stdin_line[length] = '\0';
            }
            else
            {
                stdin_line[_strcspn(stdin_line, "\n")] = '\0';
                stdin_line = _realloc(stdin_line, length + 2);
                stdin_line[length++] = character;
                if (stdin_line != NULL)
                {
                    stdin_line[length] = '\0';
                    count_nb_bytes_read++;
                }
                else
                {
                    perror("Erorre:realloc");
                    free(stdin_line);
                    return (-1);
                }
            }
        }
        else
        {
            count_nb_bytes_read++;
            stdin_line[length++] = '\0';
            break;
        }
    }
    if (count_nb_bytes_read == 0 || nb_bytes_read < 0)
    {
        free(stdin_line);
        return (-1);
    }
    if (*line != NULL)
        free(*line);
    handleComment(stdin_line);
    *line = _strdup(stdin_line);
    free(stdin_line);
    return (count_nb_bytes_read);
}
/**
 * _realloc - reallocate memory for a given pointer.
 * @ptr: the pointer we want to reallocate memory for.
 * @size: the size to reallocate.
 * Return: null in case of failure and the new allocated memory adrs.
*/
void *_realloc(void *ptr, size_t size)
{
    void *new_reallocated_ptr;
    size_t length = 0, new_lenght = 0;

    if (size == 0)
    {
        free(ptr);
        return (NULL);
    }
    if (ptr == NULL)
    {
        new_reallocated_ptr = malloc(size);
        if (new_reallocated_ptr == NULL)
            return (NULL);
        _memset(new_reallocated_ptr, '\0', size);
        return (new_reallocated_ptr);
    }
    else
    {
        length = _strlen(ptr);
        if (length > size)
        {
            new_lenght = length + size;
            new_reallocated_ptr = malloc(new_lenght);
            if (new_reallocated_ptr == NULL)
                return (NULL);
            _memset(new_reallocated_ptr, 0, new_lenght);
            _strcpy(new_reallocated_ptr, ptr);
            free(ptr);
            return (new_reallocated_ptr);
        }
        else
        {
            new_lenght = size;
            new_reallocated_ptr = malloc(new_lenght);
            if (new_reallocated_ptr == NULL)
                return (NULL);
            _memset(new_reallocated_ptr, 0, size);
            _strcpy(new_reallocated_ptr, ptr);
            free(ptr);
            return (new_reallocated_ptr);
        }
    }
}