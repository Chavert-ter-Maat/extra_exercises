
#include <stdio.h>

int anagram(char *str1, char *str2)
{
	int array[127] = {0};
	int index = 0;
	int c = 0;

	while(str1[index])
	{
		c = str1[index];
		array[c] += 1;
		index++;
	}
	index = 0;
	while(str2[index])
	{
		c = str2[index];
		array[c] -= 1;
		index++;
	}
	index = 0;
	while (index < 127)
	{
		if(array[index] != 0)
			return(0);
		index++;
	}
	return(1);
}


int main(int argc, char **argv)
{
	int ret = 0;
	if(!argv[1] || !argv[2])
	{	
		printf("wrong input");
		return(0);
	}
	ret = anagram(argv[1], argv[2]);
	printf("%i = return", ret);
	return(ret);
}
		