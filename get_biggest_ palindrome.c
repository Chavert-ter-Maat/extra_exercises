/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_biggest_ palindrome.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 15:06:13 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/03/14 14:19:37 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	string_lenght(char *string);
int compare_char(int start, int end, char *string);

int compare_char(int start, int end, char *string)
{
	while (start < end)
	{
		if (string[start] != string[end])
			return (1);
		start++;
		end--;
	}
	return (0);
}

int	string_lenght(char *string)
{
	int	index;

	index = 0;
	while (string[index])
	{
		index++;
	}
	return (index);
}

void get_pal(char *string)
{
	int	index, start, max_pal, length, pal_length;
	
	index = 0;
	start = 0;
	pal_length = 0;
	max_pal = 0;
	while (string[index])
	{
		length = string_lenght(string);
		while(string[index] && index < length)
		{
			if (string[index] == string[length])
			{
				if (compare_char(index, length, string) == 0)
				{
					pal_length = length - index;
					if (pal_length >= max_pal)
					{
						max_pal = pal_length;
						start = index;
					}
				}
			}
			length--;
		}
		index++;
	}
	write(1, &string[start], max_pal + 1);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		get_pal(argv[1]);
	write (1, "\n", 1);
	return (0);
}
