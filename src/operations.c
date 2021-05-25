#include "../push_swap.h"

/* push b*/

void		pb(stack *s)
{
	if (s->sb > 0)
		s->sb--;
	printf("pb\n");
}

/* push a*/

void		pa(stack *s)
{
	if (s->sb < s->size)
		s->sb++;
	printf("pa\n");
}


/* swap a*/

void		sa(stack *s)
{
	if (s->sb >= 2)
		swap(&s->list[s->sb - 1], &s->list[s->sb - 2]);
	printf("sa\n");
}

void		sb(stack *s)
{
	if (s->sb <= s->size - 2)
		swap(&s->list[s->sb], &s->list[s->sb + 1]);
	printf("sb\n");
}

void		ss(stack *s)
{
	if (s->sb >= 2)
		swap(&s->list[s->sb - 1], &s->list[s->sb - 2]);
	if (s->sb <= s->size - 2)
		swap(&s->list[s->sb], &s->list[s->sb + 1]);
	printf("ss\n");
}

void		ra(stack *s)
{
	if (s->sb > 1)
		rotate_right(s->list, s->sb);
	printf("ra\n");
}

void		rb(stack *s)
{
	if  (s->sb <= s->size - 2)
		rotate_left(s->list + s->sb, s->size - s->sb);
	printf("rb\n");
}

void		rr(stack *s)
{
	if (s->sb > 1)
		rotate_right(s->list, s->sb);
	if (s->sb <= s->size - 2)
		rotate_left(s->list + s->sb, s->size - s->sb);
	printf("rr\n");
}

void		rra(stack *s)
{
	if (s->sb > 1)
		rotate_left(s->list, s->sb);
	printf("rra\n");
}

void		rrb(stack *s)
{
	if  (s->sb <= s->size - 2)
		rotate_right(s->list + s->sb, s->size - s->sb);
	printf("rrb\n");
}

void		rrr(stack *s)
{
	if (s->sb > 1)
		rotate_left(s->list, s->sb);
	if  (s->sb <= s->size - 2)
		rotate_right(s->list + s->sb, s->size - s->sb);
	printf("rrr\n");
}
