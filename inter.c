/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inter.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 12:49:57 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/03/13 14:03:39 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	search_string(char *array, char a)
{
	int index;

	index = 0;
	while (array[index])
	{
		if (array[index] == a)
			return (1);
		index++;
	}

	return (0);
}

int main(int argc, char **argv)
{
	char	array[5000];
	int 	i,j,runner;

	i = 0;
	j = 0;
	if (argc == 3)
		{
			while (argv[1][i])
			{
				runner = 0;
				while (argv[2][runner])
				{
					if (argv[1][i] == argv[2][runner])
					{
						if (search_string(array, argv[1][i]) == 0)
						write(1, &argv[1][i], 1);
						array[j] = argv[1][i];
						j++;
					}
					runner++;
				}
				i++;
			}
		}
	return (0);
}