/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_wstr.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 13:00:36 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/07/07 12:08:26 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_putstr(int start, int end, char *str)
{
	int	length = end - start;
	write (1, str, length);
	
}

int	ft_strlen(char *str)
{
	int index = 0;
	
	while(str[index])
		index++;
	return(index);
}

void	rev_str(char *str)
{
	int end = ft_strlen(str) -1;
	int start = end;

	while(start >= 0)
	{
		if ((str[start] == ' ' || str[start] == '\t'))
		{
			ft_putstr(start + 1, end, &str[start]);
			end = start - 1;
		}
		start--;
	}
	ft_putstr(0, end, str);
}

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	rev_str(argv[1]);
	write(1, "\n", 1);
	return(0);
}