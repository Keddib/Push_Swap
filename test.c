#include "./push_swap.h"

void create_stack(stack *s, char **argv)
{
	
	if (!(s->list = (int *) malloc(s->size*sizeof(int)))) /* get stack memory */
	{
		printf("ERROR\n");
		exit(-1);
	}

	return;
}

int main(int argc, char **argv)
{
	stack s;

	if (argc == 1)
		return (0);
	s.size = argc - 1;
	create_stack(&s, argv);

	return 0;
}
