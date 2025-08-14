#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * id_from_sub - get unique id for s[0..wlen-1] if it matches a word
 * @s:     pointer inside big string (not null-terminated at wlen)
 * @wlen:  fixed word length
 * @uniq:  array of unique word pointers
 * @U:     number of unique words
 *
 * Return: id in [0, U) if a match is found, else -1.
 */
static int id_from_sub(const char *s, int wlen, const char **uniq, int U)
{
	int i;

	for (i = 0; i < U; i++)
	{
		if (strncmp(s, uniq[i], (size_t)wlen) == 0 &&
		    uniq[i][wlen] == '\0')
			return (i);
	}
	return (-1);
}

/**
 * build_unique - build uniq[] and need[] arrays from words
 * @words:     input words
 * @nb_words:  number of words
 * @wlen:      word length (all equal)
 * @uniq_out:  output: array of unique word pointers
 * @need_out:  output: counts for each unique word
 * @U_out:     output: number of unique words
 *
 * Return: 0 on success, -1 on failure.
 */
static int build_unique(const char **words, int nb_words, int wlen,
			const char ***uniq_out, int **need_out, int *U_out)
{
	const char **uniq;
	int *need;
	int U, i, j, found;

	uniq = (const char **)malloc(sizeof(*uniq) * (size_t)nb_words);
	need = (int *)calloc((size_t)nb_words, sizeof(*need));
	if (!uniq || !need)
	{
		free(uniq);
		free(need);
		return (-1);
	}

	U = 0;
	for (i = 0; i < nb_words; i++)
	{
		found = -1;
		for (j = 0; j < U; j++)
		{
			if (strncmp(words[i], uniq[j], (size_t)wlen) == 0 &&
			    words[i][wlen] == '\0')
			{
				found = j;
				break;
			}
		}
		if (found == -1)
		{
			uniq[U] = words[i];
			need[U] = 1;
			U++;
		}
		else
		{
			need[found]++;
		}
	}

	*uniq_out = uniq;
	*need_out = need;
	*U_out = U;
	return (0);
}

/**
 * append_ans - append a value to a dynamic int array
 * @ans:    pointer to result pointer
 * @cap:    pointer to current capacity
 * @count:  pointer to current count
 * @value:  value to append
 *
 * Return: 0 on success, -1 on allocation failure.
 */
static int append_ans(int **ans, int *cap, int *count, int value)
{
	int newcap;
	int *tmp;

	if (*count == *cap)
	{
		newcap = (*cap == 0) ? 16 : (*cap * 2);

		tmp = (int *)realloc(*ans, sizeof(int) * (size_t)newcap);
		if (!tmp)
			return (-1);

		*ans = tmp;
		*cap = newcap;
	}
	(*ans)[(*count)++] = value;
	return (0);
}

/**
 * scan_offset - sliding-window scan for a single alignment offset
 * @s:        string to scan (already shifted by base_off)
 * @s_len:    length of s
 * @wlen:     word length
 * @nbw:      number of words in a valid window
 * @uniq:     unique word pointers
 * @U:        number of unique words
 * @need:     required counts for each unique word
 * @base_off: offset relative to original base string
 * @ans:      result array pointer
 * @cap:      result capacity pointer
 * @count:    result count pointer
 *
 * Return: 0 on success, -1 on allocation failure.
 */
static int scan_offset(const char *s, int s_len, int wlen, int nbw,
		       const char **uniq, int U, const int *need,
		       int base_off, int **ans, int *cap, int *count)
{
	int left, right, words_in, idl, idr;
	int *seen;

	seen = (int *)calloc((size_t)U, sizeof(*seen));
	if (!seen)
		return (-1);

	left = 0;
	right = 0;
	words_in = 0;

	while (right + wlen <= s_len)
	{
		idr = id_from_sub(s + right, wlen, uniq, U);
		if (idr == -1)
		{
			memset(seen, 0, sizeof(*seen) * (size_t)U);
			words_in = 0;
			right += wlen;
			left = right;
			continue;
		}

		seen[idr]++;
		words_in++;
		right += wlen;

		while (seen[idr] > need[idr])
		{
			idl = id_from_sub(s + left, wlen, uniq, U);
			seen[idl]--;
			words_in--;
			left += wlen;
		}

		if (words_in == nbw)
		{
			if (append_ans(ans, cap, count, left + base_off) == -1)
			{
				free(seen);
				return (-1);
			}
			idl = id_from_sub(s + left, wlen, uniq, U);
			seen[idl]--;
			words_in--;
			left += wlen;
		}
	}
	free(seen);
	return (0);
}

/**
 * find_substring - find all start indices of concatenations of given words
 * @s:         string to scan
 * @words:     array of words (same length)
 * @nb_words:  number of words
 * @n:         out: number of indices in returned array
 *
 * Return: malloc'd array of indices (size *n) or NULL if none/error.
 */
int *find_substring(char const *s, char const **words,
		    int nb_words, int *n)
{
	const char **uniq = NULL;
	int *need = NULL;
	int *ans = NULL;
	int cap = 0, count = 0;
	int s_len, wlen, total_len, U = 0, i;

	if (n)
		*n = 0;
	if (!s || !n || !words || nb_words <= 0)
		return (NULL);

	wlen = (int)strlen(words[0]);
	if (wlen == 0)
		return (NULL);

	for (i = 1; i < nb_words; i++)
	{
		if ((int)strlen(words[i]) != wlen)
			return (NULL);
	}

	s_len = (int)strlen(s);
	total_len = nb_words * wlen;
	if (s_len < total_len)
		return (NULL);

	if (build_unique(words, nb_words, wlen, &uniq, &need, &U) == -1)
	{
		free(uniq);
		free(need);
		return (NULL);
	}

	for (i = 0; i < wlen; i++)
	{
		int sub_len = s_len - i;
		const char *sp = s + i;

		if (sub_len < total_len)
			break;

		if (scan_offset(sp, sub_len, wlen, nb_words,
				uniq, U, need, i,
				&ans, &cap, &count) == -1)
		{
			free(uniq);
			free(need);
			free(ans);
			return (NULL);
		}
	}

	free(uniq);
	free(need);

	if (count == 0)
	{
		free(ans);
		ans = NULL;
	}
	*n = count;
	return (ans);
}
