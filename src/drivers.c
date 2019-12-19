#include <stdio.h>
#include "drivers.h"

extern const int *drivers_list[];
extern const int *drivers_end[];

void iterate_drivers(void)
{
	const int **p, *d;

	printf("table");
	printf(" refs: %p %p", drivers_list, drivers_end);
	printf(" len: %zd", drivers_end - drivers_list);
	printf("\n");
	printf("items:");
	p = drivers_list;
	while (p && *p) {
		d = *p++;
		printf(" -- %p %d", d, *d);
	}
	printf(" -- end\n");
}
