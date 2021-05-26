#include "./push_swap.h"




void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main(int argc, char **argv)
{
	stack s;
	int *tmp;

	if (argc == 1)
		return (0);
	create_stack(&s, argc, argv);
	tmp = intdup(s.list, s.size);
	printArray(tmp, s.size);
	bubble_sort(tmp, s.size);
	printArray(tmp, s.size);
	return 0;
}
