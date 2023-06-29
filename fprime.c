/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fprime.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/30 11:49:40 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/06/15 09:52:57 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

	int isPrime(int num)
	{
		if (num < 2) {
			return 0;
		}

		int i = 2;
		while (i * i <= num) 
		{
			if (num % i == 0) {
				return 0;
			}
			i++;
		}

    return 1;
}

// Function to display prime factors of a number
void displayPrimeFactors(int num)
{
    int factor = 2;

    while (num > 1) {
        if (num % factor == 0) {
            printf("%d", factor);
            num /= factor;

            if (num > 1) {
                printf("*");
            }
        }
        else {
            factor++;
        }
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("\n");
        return 0;
    }

    int num = atoi(argv[1]);

    if (num <= 0) {
        printf("\n");
        return 0;
    }

    displayPrimeFactors(num);
    printf("\n");

    return 0;
}