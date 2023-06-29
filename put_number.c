/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_number.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 09:25:04 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/06/29 09:38:00 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

void putnbr(int nb)
{
	char c;
	
	if (nb == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}	
	if (nb > 9)
		putnbr(nb /10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

int main(void)
{
	int nb = 12567567;
	
	putnbr(nb);
	return 0;
}