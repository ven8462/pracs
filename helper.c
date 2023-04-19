#include "main.h"

/**
* str_len - finds string len
* @str: the string
* Return: number of chars
*/

int str_len(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}


/**
* str_cpy - copy a string.
* @src: source of string
* @dest: where we are copying it to
* Return: string copied.
*/

char *str_cpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = src[i];
	return (dest);
}

/**
* str_dup - it returns a pointer to a newly allocated memory
* which contains a copy of string being duplicated.
*
* @str: string
* Return: pointer of the duplicated string
*/
char *str_dup(char *str)
{
	int i, j;
	char *dup;

	if (str == NULL)
		return (0);
	i = 0;

	while (*(str + i) != '\0')
		i++;
	dup = malloc(i + 1);
	if (dup == 0)
		return (0);

	for (j = 0; j < i; j++)
		*(dup + j) = *(str + j);
	return (dup);
}

/**
* str_cmp - compare 2 strings
* @s1: string 1
* @s2: string 2
* Return: the difference of 2 strings, 0 on success
*/

int str_cmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

/**
*
*/
char *str_cat(char *dest, const char *src)
{
    char *temp = dest; /* store the starting address of dest */
    
    /* move the pointer to the end of dest */
    while (*dest != '\0') {
        dest++;
    }
    
    /* copy src to the end of dest */
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    
    /* add a null terminator to the end of the concatenated string */
    *dest = '\0';
    
    /* return the starting address of dest */
    return temp;
}
/**
 * _strstr - searches a string for any of a set of bytes
 * @haystack: first occurrence of the character
 * @needle: array string
 *Return: Always 0.
 */
char *_strstr(char *haystack, char *needle)
{
	int i;
	int j;
	int k;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		j = 0;
		k = i;
		while (haystack[k] == needle[j] && needle[j] != '\0')
		{
			j++;
			k++;
		}
		if (needle[j] == '\0')
		{
			return (haystack + i);
		}
	}
	return (0);
}

