
#include <unistd.h>

int	string_search(char *s, char a, int index);
int	string_search2(char *s, char a, int index);
void get_union(char *s, char *argv2);

void get_union(char *argv1, char *argv2)
{
	int index;
	int index2;

	index = 0;
	index2 = 0;
	while (argv1[index])
	{
		if (string_search(argv1, argv1[index], index) == 0)
			write(1, &argv1[index], 1);
		index++;
	}
	index = 0;
	while (argv2[index])
	{
	 if (string_search(argv2, argv2[index], index) == 0 && string_search2(argv1, argv2[index], index) == 0)
            write(1, &argv2[index], 1);
		index++;
	}
}

int	string_search(char *s, char a, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (s[i] == a)
			return (1);
		i++;
	}
	return (0);
}

int	string_search2(char *s, char a, int index)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == a)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		get_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}