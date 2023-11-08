/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   brackets.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/06 10:51:02 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/11/07 09:54:36 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

	#include <unistd.h>
	#include <stdio.h>

	int	opening_bracket(char c)
	{
		return ((c == '{') || (c == '(') || (c == '[')); //true (1)
	}
		
	int	closing_bracket(char c)
	{
		return ((c == '}') || (c == ']') || (c == ')')); //true (1)
	}

	int	brackets(char *str)
	{
		int	index = 0;
		int	top = -1;
		char stack[1024];
		if (str == "")
				return (0);
		while(str[index])
		{
			if (opening_bracket(str[index]) == 1) // true
				stack[++top] = str[index];
			if (closing_bracket(str[index]) == 1) //true
       		{
            	if ((str[index] == ']' && stack[top] == '[') ||
                	(str[index] == '}' && stack[top] == '{') ||
                	(str[index] == ')' && stack[top] == '('))
                	top--;
			}
			
			str++;
		}
			if (top != -1)
				return (0);
			return (1); //OK		
	}

	int main(int argc, char **argv)
	{
		int index = 1;
		if (argc > 2 || !argv)
			return (0);
	// printf("%s\tis %s\n", argv[1], brackets(argv[1]) ? "valid" : "invalid");
	char* test1 = "() []";		// pass
    char* test2 = "([])";		// pass
    char* test3 = "([{}])";		// pass
    char* test4 = ""; 			// fail
    char* test5 = "({[}])";		// fail
    char* test6 = "({[]}){";	// fail

    printf("%s\tis %s\n", test1, brackets(test1) ? "valid" : "invalid");
    printf("%s\tis %s\n", test2, brackets(test2) ? "valid" : "invalid");
    printf("%s\tis %s\n", test3, brackets(test3) ? "valid" : "invalid");
    printf("%s\tis %s\n", test4, brackets(test4) ? "valid" : "invalid");
    printf("%s\tis %s\n", test5, brackets(test5) ? "valid" : "invalid");
	printf("%s\tis %s\n", test6, brackets(test6) ? "valid" : "invalid");
		
		// while(argv[index])
		// {
		// 	if (brackets(argv[index])) 	
		// 	{
		// 		write(1, "OK", 2);
		// 		write(1, "\n", 1);
		// 	}
		// 	else
		// 	{
		// 		write(1, "ERROR", 5);
		// 		write(1, "\n", 1);
		// 		return (1);
		// 	}
		// 	index++;
		// }
		return (0);
	}