/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   union.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 09:31:23 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/07/07 11:45:51 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>


int		ft_verif_char(char *str, char c, int n)
{
	int		index;

	index = 0;
	while (index < n)
	{
		if (str[index] == c)
			return (0);
		index++;
	}
	return (1);
}

void	ft_union(char *str1, char *str2)
{
	int		index;
	int		len;

	index = 0;
	while (str1[index])
	{
		if (ft_verif_char(str1, str1[index], index) == 1)
			write(1, &str1[index], 1);
		index++;
	}
	len = index;
	index = 0;	
	while (str2[index])
	{
		
		if (ft_verif_char(str2, str2[index], index) == 1)	
		{
			if (ft_verif_char(str1, str2[index], len) == 1)
				write(1, &str2[index], 1);
		}
		index++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}