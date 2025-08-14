#include "regex.h"

/**
 * regex_match - Check if a pattern matches a string
 * @str: The string to scan
 * @pattern: The regular expression pattern
 *
 * Return: 1 if pattern matches string, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	/* Base cases */
	if (*pattern == '\0')
		return (*str == '\0');

	/* Check if next character is '*' */
	if (*(pattern + 1) == '*')
	{
		/* Handle x* pattern */
		/* First try matching zero occurrences of the preceding character */
		if (regex_match(str, pattern + 2))
			return (1);

		/* Then try matching one or more occurrences */
		if (*str != '\0' && (*pattern == '.' || *pattern == *str))
		{
			return (regex_match(str + 1, pattern));
		}

		return (0);
	}

	/* Handle single character match */
	if (*str != '\0' && (*pattern == '.' || *pattern == *str))
	{
		return (regex_match(str + 1, pattern + 1));
	}

	return (0);
}
