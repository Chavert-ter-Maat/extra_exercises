/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   biggest_pal2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 15:06:13 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/07/07 11:24:32 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int string_length(char *string);
int is_palindrome(int start, int end, char *string);

int is_palindrome(int start, int end, char *string)
{
    while (start < end)
    {
        if (string[start] != string[end])
            return (0);
        start++;
        end--;
    }
    return (1);
}

int string_length(char *string)
{
    int index = 0;
    while (string[index])
    {
        index++;
    }
    return index;
}

void get_pal(char* str)
{
    int maxLength = 0;
    int maxStartIndex = 0;
    int maxEndIndex = 0;
    int currentLength;
    int len = string_length(str);
    int start = 0;
    int end;

    while (start < len)
    {
        end = len - 1;
        while (start <= end)
        {
            if (start > end)
                break;
            if (is_palindrome(start, end, str))
            {
                currentLength = end - start + 1;
                if (currentLength >= maxLength)
                {
                    maxLength = currentLength;
                    maxStartIndex = start;
                    maxEndIndex = end;
                }
            }
            end--;
        }
        start++;
    }

    if (maxLength == 1)
        return;

    write(1, &str[maxStartIndex], maxLength);
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    get_pal(argv[1]);
    return (0);
}