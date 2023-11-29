/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   infin_mult.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/27 12:58:34 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/11/27 14:23:06 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str){
    int index = 0;
    
    if (!str)
        return (0);
    while(str[index])
        index++;
    return (index);
}

void	stri(char *str, int *int_str) {
	int index = 0;
	int len = ft_strlen(str);
	
	while (index < len)
	{
    	int_str[index] = str[index] - '0';
		index++;
	}
}

int ft_maxlen(char *str1, char *str2){
	if (ft_strlen(str1) > ft_strlen(str2))
		return ft_strlen(str1);
	else
		return ft_strlen(str2);
}

void	infin_mult(char *str1, char *str2){
	int	maxlen = ft_maxlen(str1, str2);
	int len_str1 = ft_strlen(str1);
	
	int	int_str1[len_str1];
	int int_array[maxlen];
	stri(str1, int_str1);
	stri(str2, int_str2);
	
	int index1 = 0;
	int index2 = 0;
	int index3 = 0;
	while (len_str1 > 0)
	{
		int len_str2 = ft_strlen(str2);	
		while(len_str2 > 0)
		{
			int_array[maxlen] = int_str1[len_str1] * int_str2[len_str2];
			index2++;
		}
		len_str1--;
	}
	
	// int int_array[maxlen + 2];
	// char char_array[maxlen + 3];


}

int main(int argc, char **argv){
    if (argc != 3)
        return 1;
    
    infin_mult(argv[1], argv[2]);
    write(1, "\n", 1);
    return 0;
}