#include <stdio.h>
#include "drivers.h"

extern const int *drivers_list[];
extern const int *drivers_end[];

void iterate_drivers(void)
{
	const int **p, *d;

	printf("refs: %p %p\n", drivers_list, drivers_end);
	printf("drivers:");
	p = drivers_list;
	printf(" %p", p);
	while (p && *p) {
		d = *p++;
		printf(" -- %p %d", d, *d);
	}
	printf("\n");
}
