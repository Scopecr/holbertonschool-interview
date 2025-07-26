#include "holberton.h"

/**
 * wildcmp - Compares two strings and returns 1 if they can be considered
 * identical. s2 can contain the special character '*'.
 * @s1: The first string
 * @s2: The second string, which can contain '*'
 *
 * Return: 1 if strings can be considered identical, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '\0')
		return (*s1 == '\0');

	if (*s2 == '*')
	{
		if (wildcmp(s1, s2 + 1))
			return (1);
		if (*s1 != '\0' && wildcmp(s1 + 1, s2))
			return (1);
	}
	else if (*s1 == *s2)
	{
		return (wildcmp(s1 + 1, s2 + 1));
	}

	return (0);
}
