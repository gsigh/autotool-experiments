#include <stdio.h>
#include "drivers.h"

void iterate_drivers(void)
{
	const struct driver_details **p, *d;

	printf("table");
	printf(" refs: %p %p", drivers_list, drivers_end);
	printf(" len: %zd", drivers_end - drivers_list);
	printf("\n");
	printf("items:\n");
	p = drivers_list;
	if (!p || !*p)
		printf("- empty -\n");
	while (p && *p) {
		d = *p++;
		printf(" %p %d %s %p\n", d,
			d->identification, d->label, d->callback);
	}
	printf("list end\n");
}

void execute_drivers(void)
{
	const struct driver_details **p, *d;
	p = drivers_list;
	while (p && *p) {
		d = *p++;
		d->callback();
	}
}
