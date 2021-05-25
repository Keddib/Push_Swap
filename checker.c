#include "./push_swap.h"


int is_sorted(stack s)
{
	int i = 0;
	if (s.sb < s.size)
		return (0);
	while (i < s.size - 1)
	{
		if (s.list[i] > s.list[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int main(int argc, char **argv)
{
	stack s;

	if (argc == 1)
		return (0);
	create_stack(&s, argc, argv);
	
	free(s.list);
	return 0;
}
