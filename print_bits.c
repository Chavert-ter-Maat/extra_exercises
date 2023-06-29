/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_bits.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/01 10:17:52 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/06/26 10:43:57 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

	#include <unistd.h>

	void print_bits(unsigned char octet)
	{
		char bit;
		
		int i = 7;
		while (i >= 0) 
		{
			bit = (octet >> i & 1) + '0';
			i--;
			write(1, &bit, 1);
		}
	}

	int main() {
		unsigned char bytes = 23;
		print_bits(bytes);
		return 0;
}