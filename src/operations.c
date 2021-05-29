#include "../push_swap.h"

/* push b*/

void		pb(data *s)
{
	if (s->sb > 0)
		s->sb--;
	printf("pb\n");
	print_stack(*s);
}

/* push a*/

void		pa(data *s)
{
	if (s->sb < s->size)
		s->sb++;
	printf("pa\n");
	print_stack(*s);
}


/* swap a*/

void		sa(data *s)
{
	if (s->sb >= 2)
		swap(&s->list[s->sb - 1], &s->list[s->sb - 2]);
	printf("sa\n");
	print_stack(*s);
}

void		sb(data *s)
{
	if (s->sb <= s->size - 2)
		swap(&s->list[s->sb], &s->list[s->sb + 1]);
	printf("sb\n");
	print_stack(*s);
}

void		ss(data *s)
{
	if (s->sb >= 2)
		swap(&s->list[s->sb - 1], &s->list[s->sb - 2]);
	if (s->sb <= s->size - 2)
		swap(&s->list[s->sb], &s->list[s->sb + 1]);
	printf("ss\n");
	print_stack(*s);
}

void		ra(data *s)
{
	if (s->sb > 1)
		rotate_right(s->list, s->sb);
	printf("ra\n");
	print_stack(*s);
}

void		rb(data *s)
{
	if  (s->sb <= s->size - 2)
		rotate_left(s->list + s->sb, s->size - s->sb);
	printf("rb\n");
	print_stack(*s);
}

void		rr(data *s)
{
	if (s->sb > 1)
		rotate_right(s->list, s->sb);
	if (s->sb <= s->size - 2)
		rotate_left(s->list + s->sb, s->size - s->sb);
	printf("rr\n");
	print_stack(*s);
}

void		rra(data *s)
{
	if (s->sb > 1)
		rotate_left(s->list, s->sb);
	printf("rra\n");
	print_stack(*s);
}

void		rrb(data *s)
{
	if  (s->sb <= s->size - 2)
		rotate_right(s->list + s->sb, s->size - s->sb);
	printf("rrb\n");
	print_stack(*s);
}

void		rrr(data *s)
{
	if (s->sb > 1)
		rotate_left(s->list, s->sb);
	if  (s->sb <= s->size - 2)
		rotate_right(s->list + s->sb, s->size - s->sb);
	printf("rrr\n");
	print_stack(*s);
}
