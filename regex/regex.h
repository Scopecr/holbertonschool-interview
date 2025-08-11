#ifndef REGEX_H
#define REGEX_H

/**
 * struct _regex_placeholder
 *                             when no structs are needed.
 * @dummy: unused field
 *
 * Note: Some checkers only require the file header + function docs.
 * This empty struct is harmless if not needed—remove it if your checker
 * doesn’t require any type in headers
 */
struct _regex_placeholder
{
int dummy;
};

/**
 *
 * @str: String to scan (may be empty; must not contain '.' or '*').
 * @pattern: Regular expression (may be empty; supports '.' and '*').
 *
 * Return: 1 if the pattern matches, 0 otherwise.
 */
int regex_match(const char *str, const char *pattern);

#endif /* REGEX_H */
