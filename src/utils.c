#include "../push_swap.h"

void		ft_exit(void)
{
	printf("ERROR\n");
	exit(1);
}

int			ft_isdigit(int c)
{
	if (c == 45)
		return (1);
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}


int			ft_isnum(const char *s)
{
	while (*s)
	{
		if (ft_isdigit(*s))
			s++;
		else
			return (0);
	}
	return (1);
}

int			not_dup(stack s, int i, int num)
{
	i++;
	while (i < s.size)
	{
		if (s.list[i] == num)
			return (0);
		i++;
	}
	return (1);
}

int			ft_atoi(const char *str, int *valid)
{
	int	i;
	int	p;
	int r;

	i = 0;
	p = 1;
	r = 0;
	*valid = ft_isnum(str);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			p = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	return (r * p);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	if (!src && !dst)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*((char*)dst + i) = *((char*)src + i);
		i++;
	}
	return (dst);
}

void bubble_sort(int *arr, int n)
{
	int i;
	int j;
	int swp;

	i = 0;
	while (i < n)
	{
		j= 0;
		swp = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
				swp = 1;
			}
			j++;
		}
		if (swp == 0)
			return;
		i++;
	}
}

int * intdup(const int *src, size_t len)
{
   int * p = malloc(len * sizeof(int));
   ft_memcpy(p, src, len * sizeof(int));
   return p;
}

