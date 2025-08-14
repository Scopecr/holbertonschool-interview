#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * find_in_unique - find index of a word in the unique list by strcmp
 * @w:    null-terminated word to find
 * @uniq: array of unique word pointers
 * @U:    number of unique words currently stored
 *
 * Return: index in uniq if found, else -1.
 */
static int find_in_unique(const char *w, const char **uniq, int U)
{
    int i;

    for (i = 0; i < U; i++)
    {
        if (strcmp(w, uniq[i]) == 0)
            return (i);
    }
    return (-1);
}

/**
 * id_from_sub - find id of the unique word matching s[0..wlen-1]
 * @s:     pointer into the big string (not null-terminated at wlen)
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
        if (strncmp(s, uniq[i], (size_t)wlen) == 0 && uniq[i][wlen] == '\0')
            return (i);
    }
    return (-1);
}

/**
 * find_substring - find all starting indices where a concat of all words appears
 * @s:         string to scan
 * @words:     array of words (all same length)
 * @nb_words:  number of words in the array
 * @n:         out-parameter: will receive result count
 *
 * Return: malloc'd array of starting indices (size *n), or NULL if none.
 *         On error, returns NULL and sets *n = 0.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int i, wlen, total_len, s_len;
    int *ans = NULL, cap = 0, count = 0;
    const char **uniq = NULL;  /* pointers to first occurrence of each unique word */
    int *need = NULL;          /* required counts for each unique word */
    int U = 0;                 /* number of unique words */

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

    uniq = (const char **)malloc(sizeof(*uniq) * (size_t)nb_words);
    need = (int *)calloc((size_t)nb_words, sizeof(*need));
    if (!uniq || !need)
        goto cleanup;

    /* Build list of unique words and required counts (no copies, just pointers) */
    for (i = 0; i < nb_words; i++)
    {
        int id = find_in_unique(words[i], uniq, U);

        if (id == -1)
        {
            uniq[U] = words[i];
            need[U] = 1;
            U++;
        }
        else
        {
            need[id]++;
        }
    }

    /* Prepare answer buffer */
    cap = 16;
    ans = (int *)malloc(sizeof(*ans) * (size_t)cap);
    if (!ans)
        goto cleanup;

    /* For each alignment offset in [0, wlen) */
    for (i = 0; i < wlen; i++)
    {
        int left = i, right = i, words_in = 0;
        int *seen = (int *)calloc((size_t)U, sizeof(*seen));

        if (!seen)
            goto cleanup;

        while (right + wlen <= s_len)
        {
            int idr = id_from_sub(s + right, wlen, uniq, U);

            if (idr == -1)
            {
                /* Reset window on unknown chunk */
                memset(seen, 0, sizeof(*seen) * (size_t)U);
                words_in = 0;
                right += wlen;
                left = right;
                continue;
            }

            seen[idr]++;
            words_in++;
            right += wlen;

            /* Shrink from left if this word is over-represented */
            while (seen[idr] > need[idr])
            {
                int idl = id_from_sub(s + left, wlen, uniq, U);

                seen[idl]--;
                words_in--;
                left += wlen;
            }

            /* If window has exactly nb_words words, record index and slide by one word */
            if (words_in == nb_words)
            {
                if (count == cap)
                {
                    int *tmp;
                    cap *= 2;
                    tmp = (int *)realloc(ans, sizeof(*ans) * (size_t)cap);
                    if (!tmp)
                    {
                        free(seen);
                        goto cleanup;
                    }
                    ans = tmp;
                }
                ans[count++] = left;

                /* Move left forward one word to keep searching overlapping matches */
                {
                    int idl = id_from_sub(s + left, wlen, uniq, U);

                    seen[idl]--;
                    words_in--;
                    left += wlen;
                }
            }
        }
        free(seen);
    }

    if (count == 0)
    {
        free(ans);
        ans = NULL;
    }
    *n = count;

cleanup:
    free(uniq);
    free(need);
    return (ans);
}
