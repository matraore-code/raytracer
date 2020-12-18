#include "tuples.h"
#include <stdio.h>

int main ()
{
	t_tuple p = create_point(2, 2 ,3);
	t_tuple v = create_vector(2, 4, 5);
	int i = is_equal(2.0, 1.9999999999);
	printf("p (%.2f %.2f %.2f %.2f)\n", p.x, p.y, p.z, p.w);
	printf("v (%.2f %.2f %.2f %.2f)\n", v.x, v.y, v.z, v.w);
	printf(" i = %d ", i);
	return (0);
}
