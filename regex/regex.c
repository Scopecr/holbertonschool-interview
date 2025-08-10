#include "regex.h"

/**
 * match_here - Recursive helper that matches from current positions.
 * @s: Current position in the input string.
 * @p: Current position in the pattern.
 *
 * Return: 1 if the suffix of @s matches the suffix of @p, 0 otherwise.
 */
static int match_here(const char *s, const char *p)
{
	int first_match = 0;

	/* If pattern is exhausted, we match only if string is also exhausted */
	if (*p == '\0')
		return (*s == '\0');

	/* Invalid if pattern chunk begins with '*' */
	if (*p == '*')
		return (0);

	/* Does current character match? */
	first_match = (*s != '\0') && (*p == '.' || *p == *s);

	/* Handle 'x*' (zero or more of the preceding character) */
	if (p[1] == '*')
		return (match_here(s, p + 2) ||
			(first_match && match_here(s + 1, p)));

	/* Otherwise, advance both if current chars match */
	return (first_match && match_here(s + 1, p + 1));
}

/**
 * regex_match - Check if a pattern matches a string.
 * @str: String to scan.
 * @pattern: Pattern to match against.
 *
 * Return: 1 if match, 0 otherwise.
 */
int regex_match(const char *str, const char *pattern)
{
	if (!str || !pattern)
		return (0);

	return (match_here(str, pattern) ? 1 : 0);
}
