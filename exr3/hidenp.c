/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hidenp.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/30 13:45:58 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/06/22 09:51:39 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void hidenp(char *str1, char *str2)
{
	int index1 = 0;
	int index2 = 0;

	while (str1[index1] && str2[index2])
	{
		if(str1[index1] == str2[index2])
				index1++;
		index2++;
	}
	if(str1[index1] == '\0')
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

int	main(int argc, char **argv)
{
	if ((argc != 3) || argv[1] == NULL || argv[2] == NULL)
	{
		write(1, "\n", 1);
		return(0);
	}
	hidenp(argv[1], argv[2]);
	write(1, "\n", 1);
	return(0);
}