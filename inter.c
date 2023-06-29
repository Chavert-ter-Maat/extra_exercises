/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inter.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 10:42:40 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/05/29 14:24:22 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

int	is_presents2(char *str, char character)
{
	int index = 0;
	while(str[index])
	{
		if(str[index] == character)
			return(true);
		index++;
	}
	return(false);
}

int	is_presents1(char *str, char character, int count)
{
	int index = 0;
	
	while(str[index] && index < count)
	{
		if(str[index] == character)
			return(true);
		index++;
	}
	return(false);
}

void	display_doubles(char *str1, char *str2)
{
	int index = 0;
	char character;

	while(str1[index])
	{
		character = str1[index];
		if(is_presents2(str2, character) == true)
		{
			if (is_presents1(str1, character, index) == false)
				write(1, &character, 1);
		}
		index++;
	}	
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{	
	if (argc != 3)
	{
		write(1, "\n", 1);
		return(1);
	}
	char *str1 = argv[1];
	char *str2 = argv[2];
	display_doubles(str1, str2);
	return(0);		
}
