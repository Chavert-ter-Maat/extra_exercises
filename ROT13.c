#include <stdio.h>
#include <ctype.h>

void rot_13(char *string) 
{
    while (*string != '\0') 
	{
        if (islower(*string)) 
		{
            *string = ((*string - 'a' + 13) % 26) + 'a';
        } 
		else if (isupper(*string)) 
		{
            *string = ((*string - 'A' + 13) % 26) + 'A';
        }
        string++;
    }
}

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
	{
        printf("\n");
    } else 
	{
        char *input_string = argv[1];
        rot_13(input_string);
        printf("%s\n", input_string);
    }
    return 0;
}