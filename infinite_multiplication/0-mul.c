#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c);

/**
 * print_error - prints Error and exits with status 98
 */
void print_error(void)
{
    _putchar('E');
    _putchar('r');
    _putchar('r');
    _putchar('o');
    _putchar('r');
    _putchar('\n');
    exit(98);
}

/**
 * is_digit_string - checks if a string contains only digits
 * @str: string to check
 *
 * Return: 1 if all digits, 0 otherwise
 */
int is_digit_string(char *str)
{
    int i;
    
    if (!str || *str == '\0')
        return (0);
    
    for (i = 0; str[i]; i++)
    {
        if (!isdigit(str[i]))
            return (0);
    }
    return (1);
}

/**
 * print_number - prints a number stored as string using _putchar
 * @num: string representation of number
 */
void print_number(char *num)
{
    int i;
    
    for (i = 0; num[i]; i++)
        _putchar(num[i]);
    _putchar('\n');
}

/**
 * multiply_strings - multiplies two number strings
 * @num1: first number as string
 * @num2: second number as string
 *
 * Return: result as dynamically allocated string
 */
char *multiply_strings(char *num1, char *num2)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int result_len = len1 + len2;
    char *result;
    int i, j, carry, sum, n1, n2;
    
    /* Allocate memory for result */
    result = calloc(result_len + 1, sizeof(char));
    if (!result)
        print_error();
    
    /* Initialize result with zeros */
    for (i = 0; i < result_len; i++)
        result[i] = '0';
    result[result_len] = '\0';
    
    /* Multiply each digit */
    for (i = len1 - 1; i >= 0; i--)
    {
        carry = 0;
        n1 = num1[i] - '0';
        
        for (j = len2 - 1; j >= 0; j--)
        {
            n2 = num2[j] - '0';
            sum = (result[i + j + 1] - '0') + (n1 * n2) + carry;
            carry = sum / 10;
            result[i + j + 1] = (sum % 10) + '0';
        }
        
        if (carry > 0)
            result[i + j + 1] = (result[i + j + 1] - '0' + carry) + '0';
    }
    
    return (result);
}

/**
 * remove_leading_zeros - removes leading zeros from number string
 * @num: number string
 *
 * Return: pointer to first non-zero digit
 */
char *remove_leading_zeros(char *num)
{
    while (*num == '0' && *(num + 1) != '\0')
        num++;
    return (num);
}

/**
 * main - Entry point for multiplication program
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
    char *result, *clean_result;
    
    /* Check argument count */
    if (argc != 3)
        print_error();
    
    /* Check if arguments are valid digit strings */
    if (!is_digit_string(argv[1]) || !is_digit_string(argv[2]))
        print_error();
    
    /* Multiply the numbers */
    result = multiply_strings(argv[1], argv[2]);
    
    /* Remove leading zeros */
    clean_result = remove_leading_zeros(result);
    
    /* Print result */
    print_number(clean_result);
    
    /* Free allocated memory */
    free(result);
    
    return (0);
}