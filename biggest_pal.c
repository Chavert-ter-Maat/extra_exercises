/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   oefen.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: Invalid date        by               #+#    #+#                 */
/*   Updated: 2023/05/31 16:50:13 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_pal(char *s, int start, int end)
{
	while(start < end)
	{
		if(s[start] != s[end])
			return(1); // no pal
		end--;
		start++;
	}
	return(0); // yes pal
}
int	string_lenght(char *string)
{
	int	index;

	index = 0;
	while (string[index])
		index++;
	return (index);
}

void	ft_get_pal(char *s)
{
	int index = 0;
	int start = 0;
	int length = 0;
	int pal_length = 0;
	int max_pal = 0;

	while(s[index])
	{
		length = string_lenght(s);
		while(s[index] && index < length)
		{
			if(s[index] == s[length])
			{
				if(check_pal(s, index, length) == 0)
				{
					pal_length = length - index;
					if(pal_length >= max_pal)
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
	write(1, &s[start], max_pal +1);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		ft_get_pal(argv[1]);
	write (1, "\n", 1);
	return (0);
}
