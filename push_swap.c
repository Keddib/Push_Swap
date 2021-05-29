#include "./push_swap.h"


void	init_partitions(data *d)
{
	d->PA = ft_lstnew(0, d->sb);
	d->PB = ft_lstnew(d->sb, d->sb);
}


int		get_pivo(data d, int side, int *pd)
{
	int size;
	int *arr;

	if (side)
	{
		arr = d.tmp + d.PB->index[0];
		size = d.PB->index[1] - d.PB->index[0];
		*pd = size / 2;
		return (arr[size / 2]);
	}
	else
	{
		arr = d.tmp + d.PA->index[0];
		size = d.PA->index[1] - d.PA->index[0];
		if (size % 2 == 0)
		{
			*pd = (size / 2);
			return (arr[(size / 2) - 1]);
		}
	}
	*pd = size / 2;
	return (arr[size / 2]);
}

void	B_to_A_direct(data *d)
{
	int i = 0;
	while (i < d->PB->index[1] - d->PB->index[0])
	{
		pa(d);
		d->PA->index[1] += 1;
		i++;
	}
	ft_lstdelete_front(&d->PB);
}

void	B_to_A(data *d)
{
	int p;
	int pd;
	t_partition *na;
	int rotate = ft_lstsize(d->PB);
	if (is_p_sorted(d->list, d->PB))
		B_to_A_direct(d);
	else
	{
		na = ft_lstnew(d->PA->index[1], d->PA->index[1]);
		ft_lstadd_front(&d->PA, na);
		p = get_pivo(*d, 1, &pd);
		printf("p = %d | pd = %d\n", p, pd);
		while (pd > 0)
		{
			if (d->list[d->sb] > p)
			{
				pa(d);
				d->PB->index[0] += 1;
				d->PA->index[1] += 1;
				pd--;
			}
			else
			{
				rb(d);
				if (rotate > 1)
					rotate++;
			}
		}
		ft_lstdelete_front(&d->PB);
		while (rotate > 1)
		{
			rrb(d);
			rotate--;
		}
	}
}

void	A_to_B(data *d)
{
	int p;
	int pd;
	t_partition *na;
	//
	int rotate = ft_lstsize(d->PA);
	p = get_pivo(*d, 0, &pd);
	printf("p = %d | pd = %d\n", p, pd);
	if (d->PB->index[0] != d->PB->index[1])
	{
		na = ft_lstnew(d->PB->index[0], d->PB->index[0]);
		ft_lstadd_front(&d->PB, na);
	}
		printf("-----\n");
	while (pd > 0)
	{
		if (d->list[d->sb -1] < p)
		{
			pb(d);
			d->PA->index[1] -= 1;
			d->PB->index[0] -= 1;
			pd--;
		}
		else
		{
			ra(d);
			if (rotate > 1)
				rotate++;
		}
	}
	while (rotate > 1)
	{
		rra(d);
		rotate--;
	}
	printf("0 = %d | 1 = %d \n", d->PB->index[0], d->PB->index[1]);
}

void	quick_sort(data *d)
{
	while (1)
	{
		if (is_sorted(*d))
		{
			printf("hello word\n");
			break;
		}
		else if (is_p_sorted(d->list, d->PA))
		{
			printf(" A is sorted\n");
			B_to_A(d);
		}
		else
		{
			printf(" A to B\n");
			A_to_B(d);
		}
	}
}

void	print_array(int *arr, int size)
{
	int i = 0;
	while (i < size)
	{
		printf("%d |", arr[i]);
		i++;
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	data data;

	if (argc == 1)
		return (0);
	create_stack(&data, argc, argv);
	data.tmp = intdup(data.list, data.size);
	init_partitions(&data);
	printf("s = %d\n", ft_lstsize(data.PA));
	bubble_sort(data.tmp, data.size);
	print_stack(data);
	quick_sort(&data);
	return 0;
}
