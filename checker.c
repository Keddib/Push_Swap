#include "./push_swap.h"


void do_operation(char *str, stack *s)
{
	s->size++;
	printf("s = %s\n", str);
	return;
}

int main(int argc, char **argv)
{
	stack s;
	char *inst;

	inst = NULL;
	if (argc == 1)
		return (0);
	create_stack(&s, argc, argv);
	print_stack()
	free(s.list);
	return 0;
}
