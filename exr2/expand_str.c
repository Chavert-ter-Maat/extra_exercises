/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_str2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 09:58:55 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/06/22 10:48:42 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void expand(char *str)
{
	int index = 0;
	int yes_word = 0;

	while(str[index])
	{
		while((str[index] == ' ' || (str[index] == '\t')))
			index++;
		if(str[index] == '\0')
			break;
		if(yes_word == 1)
			write(1, "   ", 3);
		while((str[index] != ' ' && str[index] != '\t') && str[index])
		{
			write(1, &str[index], 1);
			yes_word = 1;
			index++;
		}
	}
}

int main(int argc, char **argv)
{
	if(argc !=2 || argv[1] == NULL)
	{
		write(1, "\n", 1);
		return(0);
	}
	expand(argv[1]);
	write(1, "\n", 1);
	return(0);
}