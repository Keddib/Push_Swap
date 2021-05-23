#include <unistd.h>
#include <stdio.h>

int is_digit(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] < 48 && s[i] > 57 && s[i] != 45)
			return (1);
		i++;
	}
	return (0);
}

int check_args(char **args)
{
	int i;
	int j;

	i = 0;
	while (args[i])
	{
		if (!is_digit(args[i]))
			return (1);
		i++;
	}
	return (0);
}


int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	printf("%s\n", argv[1]);
	printf("%d\n", is_digit(argv[1]));

	return (0);
}
