/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_bits.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 10:59:44 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/06/28 10:59:47 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

unsigned char	swap_bits(unsigned char octet) 
{
    return (octet >> 4) | (octet << 4);
}	