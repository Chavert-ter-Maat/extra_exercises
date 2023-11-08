/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rostring.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/30 11:59:45 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/05/30 12:41:20 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	write_words(char *str)
{
	int	end_first = 0;
	int	start_word = 0;
	int	end_word = 0;
	int	index = 0;

	while(str[index])
	{
		if((str[index] == ' ' || str[index] == '\t'))
		{
			end_first = index;
			break ;
		}
		index++;
	}
	while(str[index])
	{
		if((str[index] == ' ' || str[index] == '\t'))
		{
			write(1 , " ", 1);
		}
		else
			write(1, &str[index], 1);
		index++;
	} 
	write (1, " ", 1);
	write(1, &str[0], end_first);
}

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	write_words(argv[1]);
	write(1, "\n", 1);
	return(0);
}