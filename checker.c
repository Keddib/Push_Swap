#include "./push_swap.h"


void do_operation(char *str, data *s)
{
	s->size++;
	printf("s = %s\n", str);
	return;
}

int main(int argc, char **argv)
{
	data s;
	char *inst;

	inst = NULL;
	if (argc == 1)
		return (0);
	create_data(&s, argc, argv);
	print_data()
	free(s.list);
	return 0;
}
