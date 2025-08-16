#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * strncmp_helper - Helper function to compare n characters
 * @s1: First string
 * @s2: Second string
 * @n: Number of characters to compare
 *
 * Return: 0 if equal, non-zero otherwise
 */
static int strncmp_helper(const char *s1, const char *s2, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] == '\0')
			return (0);
	}
	return (0);
}

/**
 * check_substring - Check if substring starting at index
 * forms valid concatenation
 * @s: String to check
 * @start: Starting index
 * @words: Array of words
 * @nb_words: Number of words
 * @word_len: Length of each word
 *
 * Return: 1 if valid substring found, 0 otherwise
 */
static int check_substring(char const *s, int start, char const **words,
		int nb_words, int word_len)
{
	int *used;
	int i, j, found;

	used = calloc(nb_words, sizeof(int));
	if (!used)
		return (0);

	for (i = 0; i < nb_words; i++)
	{
		found = 0;
		for (j = 0; j < nb_words; j++)
		{
			if (!used[j] &&
					strncmp_helper(s + start + i * word_len, words[j], word_len) == 0)
			{
				used[j] = 1;
				found = 1;
				break;
			}
		}
		if (!found)
		{
			free(used);
			return (0);
		}
	}

	free(used);
	return (1);
}

/**
 * find_substring - Find all substrings that are concatenations of given words
 * @s: String to scan
 * @words: Array of words
 * @nb_words: Number of words
 * @n: Address to store number of results
 *
 * Return: Array of indices where substrings start, or NULL if none found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *result;
	int s_len, word_len, total_len, max_results;
	int i, count = 0;

	*n = 0;

	if (!s || !words || nb_words == 0)
		return (NULL);

	s_len = strlen(s);
	word_len = strlen(words[0]);
	total_len = word_len * nb_words;

	if (s_len < total_len || word_len == 0)
		return (NULL);

	/* Maximum possible results */
	max_results = s_len - total_len + 1;
	result = malloc(max_results * sizeof(int));
	if (!result)
		return (NULL);

	for (i = 0; i <= s_len - total_len; i++)
	{
		if (check_substring(s, i, words, nb_words, word_len))
		{
			result[count] = i;
			count++;
		}
	}

	if (count == 0)
	{
		free(result);
		return (NULL);
	}

	*n = count;
	return (result);
}
