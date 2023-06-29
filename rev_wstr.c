/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_wstr.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 13:00:36 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/05/30 11:44:11 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_putstr(int start, int end, char *str)
{
	int	length = end - start;
	write (1, str, length);
	write (1, " ", 1);
	
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
	int	start = 0;
	int end = ft_strlen(str);
	int index = end;

	while(index > 0)
	{
		if ((str[index] == ' ' || str[index] == '\t'))
		{
			start = index;
			ft_putstr(start, end, &str[index]);
			end = start;
		}
		index--;
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