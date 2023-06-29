
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* camel_to_snake(const char* str)
{
    if (str == NULL || *str == '\0')
        return NULL;
    size_t len = strlen(str);
    size_t str_index = 0;
    size_t result_index = 0;
    char* result = malloc((2 * len + 1) * sizeof(char));
    if (result == NULL)
        return NULL;
    while (str[str_index]) 
	{
        if (str_index > 0 && isupper(str[str_index]))
            result[result_index++] = '_'; 
        result[result_index++] = tolower(str[str_index]);
    }
    result[result_index] = '\0';
    return result;
}

int main(int argc, char* argv[]) 
{
    if (argc != 2) 
        return 1;
    const char* input = argv[1];
    char* result = camel_to_snake(input);
    if (result == NULL) 
        return 1;
    free(result);
    return 0;
}