/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_test.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: chaverttermaat <chaverttermaat@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 10:22:46 by chavertterm   #+#    #+#                 */
/*   Updated: 2022/11/19 12:08:04 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int max(int num_args, ...)
{
	va_list list;
	int     i;
	int		x;
	int		max;

	i = 0;
	x = 0;
	max = 0;	
	va_start(list, num_args);
	while (i < num_args)
	{
		x = va_arg(list, int);
		if (x == 0) 
			max = x;
		if (x > max)
			max = x;
		i++;
	}
	va_end(list);
	return(max);
}

int main(void)
{
	printf("max number = %i", max(4, 2, 11, 123, 4555));
	return (0);
}