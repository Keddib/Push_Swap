#include "../push_swap.h"

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

void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	rotate_right(int *arr, int size)
{

	int j;
	int last;

	last = arr[size - 1];
	j = size - 1;
	while (j > 0)
	{
		arr[j] = arr[j - 1];
		j--;
	}
	arr[0] = last;
}

void	rotate_left(int *arr, int size)
{

	int j;
	int first;

	first = arr[0];
	j = 0;
	while (j < size - 1)
	{
		arr[j] = arr[j + 1];
		j++;
	}
	arr[j] = first;
}


void	create_stack(stack *s, int argc, char **argv)
{
	int i;
	int valid;
	int num;

	s->size = argc - 1;
	s->sb = s->size;
	if (!(s->list = (int *) malloc(s->size*sizeof(int))))
		ft_exit();
	i = s->size - 1;
	argv++;
	while (*argv)
	{
		num = ft_atoi(*argv, &valid);
		if (valid && not_dup(*s, i, num))
			s->list[i] = num;
		else
			ft_exit();
		argv++;
		i--;
	}
	return;
}

void	print_stack(stack s)
{
	printf("A| ");
	int i = s.sb - 1;
	int j = s.sb;
	int b;
	int a;
	while (i >= 0)
	{

		if (i < 0)
			a = 0;
		else
			a = s.list[i];
		printf("%3d | ", a);
		i--;
	}
	printf("\n");
	printf("--------------------------------------------------------\n");
	printf("B| ");
	while (j < s.size)
	{
		if (j>= s.size)
			b = 0;
		else
			b = s.list[j];
		printf("%3d | ", b);
		j++;
	}
	printf("\n\n\n");
}
