#include "main.h"
/**
 * _memset - will fill a block of memory with a the value provided
 * @destination: the destination the user wants to fill.
 * @character: the value destination will be filled with.
 * @number_bytes_memory_to_fill: number of bytes in memory to fill.
 * Return: NULL in case of failure or the destination filled with the @character.
*/
void *_memset(void *destination, int character, size_t number_bytes_memory_to_fill)
{
	size_t length = 0, i = 0;
	char *costumised_dest = NULL;

    if (destination != NULL)
    {
		costumised_dest = (char *)destination;
		length = sizeof(costumised_dest);
		if (number_bytes_memory_to_fill == 0)
		{
			return (NULL);
		}
		if (number_bytes_memory_to_fill > length)
		{
			return (NULL);
		}
		else
		{
			while (i < number_bytes_memory_to_fill - 1)
			{
				costumised_dest[i] = (char)character;
				i++;
			}
			costumised_dest[i] = '\0';
			return (costumised_dest);
        }
	}
    return (NULL);
}