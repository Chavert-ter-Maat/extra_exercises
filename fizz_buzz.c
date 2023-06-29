#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void putnbr(int nb)
{
	if (nb > 9)
        {
            putnbr(nb / 10);
            putnbr(nb % 10);
        }
        else
          ft_putchar(nb + '0');
}

int	main(void)
{
	int	nb;

	nb = 1;
	while( nb <= 100)
	{
        if (nb % 15 == 0)
            write(1, "fizzbuzz", 9);
        else if (nb % 3 == 0)
            write(1, "fizz\n", 3);
		else if (nb % 5 == 0)
           write(1, "buzz\n", 3);
		else
			putnbr(nb);
		write(1, "\n", 1);
		nb++;
	}
	return(0);
}

