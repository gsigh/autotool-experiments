#include <stdio.h>
#include "drivers.h"

void iterate_drivers(void)
{
	const struct driver_details **p, *d;

	printf("table");
	printf(" refs: %p %p", drivers_list, drivers_end);
	printf(" len: %zd", drivers_end - drivers_list);
	printf("\n");
	printf("items:");
	p = drivers_list;
	while (p && *p) {
		d = *p++;
		printf(" -- %p %d %s %p", d,
			d->identification, d->label, d->callback);
	}
	printf(" -- end\n");
}
