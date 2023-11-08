/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   html_validator.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/06 13:41:17 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/11/07 10:34:58 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int opening_tag(char *str) {
    return (str[0] == '<' && str[1] != '/');
}

int closing_tag(char *str) {
    return (str[0] == '<' && str[1] == '/');
}

int validHtml(const char *str) 
{
    int i = 0;
    int stack_size = -1;
	
    const char **stack = malloc(1054 * sizeof(const char *));
    if (!stack)
        return 0;
    while (str[i]) 
	{
        if (opening_tag(&str[i])) 
		{
            stack[++stack_size] = &str[i + 1];
            while (str[i] != '>')
                i++;
        } 
		else if (closing_tag(&str[i])) 
		{
            while (stack_size >= 0) 
			{
                if (strncmp(&str[i + 2], stack[stack_size], i - 2 - (int)(stack[stack_size] - str)) == 0) 
				{
                    stack_size--;
                    break;
                } 
				else 
				{
                    free(stack);
                    return 0;
                }
            }
            while (str[i] != '>')
                i++;
        }
        i++;
    }

    free(stack);
    return (stack_size == -1); //true/return 1
}

int main(int argc, char **argv) {
	if (argc > 2 || !argv)
		return (0);
	// printf("%s\tis %s\n", argv[1], validHtml(argv[1]) ? "valid" : "invalid");
	char* test1 = "<head></head>";	// pass
    char* test2 = "<head><head>"; 	// fail
    char* test3 = "<head></head><head></head>";	// pass
    char* test4 = "<head></second><second></head>"; 	// fail
	char* test5 = "<head></head><second></second>"; 	// fail
    char* test6 = "<s></s>";	// ??
    char* test7 = "</head></head>";	// fail
	char* test8 = "</head><head>";	// fail
	char* test9 = "/<head><head>";	// fail
	char* test10 = "/////<head></head>";	// fail

    printf("%s\tis %s\n\n", test1, validHtml(test1) ? "valid" : "invalid");
    printf("%s\tis %s\n\n", test2, validHtml(test2) ? "valid" : "invalid");
    printf("%s\tis %s\n\n", test3, validHtml(test3) ? "valid" : "invalid");
    printf("%s\tis %s\n\n", test4, validHtml(test4) ? "valid" : "invalid");
    printf("%s\tis %s\n\n", test5, validHtml(test5) ? "valid" : "invalid");
	printf("%s\tis %s\n\n", test6, validHtml(test6) ? "valid" : "invalid");
	printf("%s\tis %s\n\n", test7, validHtml(test7) ? "valid" : "invalid");
	printf("%s\tis %s\n\n", test8, validHtml(test8) ? "valid" : "invalid");
	printf("%s\tis %s\n\n", test9, validHtml(test9) ? "valid" : "invalid");
	printf("%s\tis %s\n\n", test10, validHtml(test10) ? "valid" : "invalid");
    return (0);
}