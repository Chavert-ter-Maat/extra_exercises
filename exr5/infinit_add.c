/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   infinit_add.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/27 09:25:28 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/11/27 10:40:28 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str){
    int index = 0;
    
    if (!str)
        return (0);
    while(str[index])
        index++;
    return (index);
}

char *ft_calloc(char *str, int i){
    int index = 0;
    str = malloc((sizeof(char) * i) + 1);
    if (str == NULL)
        return (NULL);
    while (index < i)
    {
        str[index] = '\0';
        index++;
    }
    return (str);
}

int charToInt(char c) {
    if (c >= '0' && c <= '9') 
        return c - '0';
    else
        return 0;
}

void    add_nb(char str1, char str2){
    int nb1 = 0;
    int nb2 = 0;
    int result_int;
    char result_char = '\0';
    
    result_int = ((nb1 = charToInt(str1)) + (nb2 = charToInt(str2)));
    printf("%i", result_int);
}

void    infin_add(char *str1, char *str2){
    // char *array = NULL;
    int index = 0;
    int strlen1 = ft_strlen(str1); 
    int strlen2 = ft_strlen(str2);
    int maxlen = 0;
    if (strlen1 > strlen2)
        maxlen = strlen1;
    else 
        maxlen = strlen2;
    while (index < maxlen)
    {
        add_nb(str1[index], str2[index]);
        index++;
    }
    // array = ft_calloc(array, 3);

}

int main(int argc, char **argv){
    if (argc != 3)
        return 1;
    // int strlen = ft_strlen(argv[1]); //strlen test
    // printf("%i", strlen);
    
    infin_add(argv[1], argv[2]);
    write(1, "\n", 1);
    return 0;
}