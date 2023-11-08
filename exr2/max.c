#include <stdio.h>

int max(int *tab, unsigned int len)
{
	if (len == 0)
		return (0);
	
	unsigned int result;
	unsigned int i = 0;
	
	result = tab[i];
	while(i < len)
	{
		if (result <  tab[i])
		{
			result = tab[i];
		}
		i++;
	}
	return result;
}

int main(void)
{
	int	tab[] = {10, 5, 9999};
	unsigned int len = 3;
	int result;

	result = max(tab, len);
	printf("%i", result);
	return(0);
}