#include <stdio.h> // remove before pushing!
#include <stdlib.h>

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	word_count(char *str)
{
	int	count = 0;

	while(*str)
	{
		while(*str && ft_isspace(*str))
			str++;
		if(*str && !ft_isspace(*str))
		{
			count++;
			while(*str && !ft_isspace(*str))
				str++;
		}
	}
	return(count);
}

char	*malloc_word(char *str)
{
	char	*word;
	int		i = 0;
	while(str[i] && !ft_isspace(str[i]))
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if(!word)
		return(NULL);
	i = 0;
	while(str[i] && !ft_isspace(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return(word);
}

char	**ft_split(char *str)
{
	char **array;
	int	j = 0;

	array = malloc(sizeof(char *) * (word_count(str) + 1));
	if(!array)
		return(NULL);
	while(*str)
	{
		while(*str && ft_isspace(*str))
			str++;
		if(*str && !ft_isspace(*str))
		{
			array[j] = malloc_word(&*str);
			j++;
			while(*str && !ft_isspace(*str))
				str++;
		}
	}
	array[j] = NULL;
	return(array);
}

int	main(int argc, char **argv)
{
	if(argc != 2)
		return(1);
	char **array;
	int	j = 0;

	printf("word count = %i\n", word_count(argv[1]));
	array = ft_split(argv[1]);
	while(array[j])
	{
		printf("%s\n", array[j]);
			j++;
	}
	return(0);
}