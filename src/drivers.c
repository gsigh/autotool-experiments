#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "drivers.h"

#define USE_LINKER_SECTION	1
#define USE_CONSTRUCTORS	2
#define USE_APPROACH		USE_CONSTRUCTORS

/*
 * The runtime registration approach involves a compile time constant
 * upper limit for the number of available drivers. The registration
 * calls are done from "constructors" before main() executes, it's yet
 * to get determined if malloc(3) is available at this time (that is:
 * universally, on all platforms that are supported by sigrok).
 *
 * It's an implementation detail to count the number of overflows and to
 * communicate these conditions to calling application code. Callers can
 * raise a warning or severe error or whatever seems appropriate.
 */
#define DRIVERS_MAX_COUNT 10

#ifndef ARRAY_SIZE
#  define ARRAY_SIZE(x)	(sizeof(x) / sizeof(x[0]))
#endif

static struct driver_details const *drivers_table[DRIVERS_MAX_COUNT];
static size_t drivers_count;
static int drivers_exceed;

void register_driver(const struct driver_details *details) {

	if (drivers_count == ARRAY_SIZE(drivers_table)) {
		drivers_exceed++;
		return;
	}
	drivers_table[drivers_count++] = details;
}

void iterate_drivers(void)
{
#if USE_APPROACH == USE_LINKER_SECTION
	extern const struct driver_details *drivers_list[];
	extern const struct driver_details *drivers_end[];

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
#elif USE_APPROACH == USE_CONSTRUCTORS
	size_t count;
	const struct driver_details *d;

	printf("items:\n");
	for (count = 0; count < drivers_count; count++) {
		d = drivers_table[count];
		printf(" %p %d %s %p\n", d,
			d->identification, d->label, d->callback);
	}
	if (drivers_exceed)
		printf("%zu drivers could NOT register.\n", drivers_exceed);
	printf("list end\n");
#else
#  error "unsupported driver iteration approach"
#endif
}

void execute_drivers(void)
{
#if USE_APPROACH == USE_LINKER_SECTION
	const struct driver_details **p, *d;

	p = drivers_list;
	while (p && *p) {
		d = *p++;
		d->callback();
	}
#elif USE_APPROACH == USE_CONSTRUCTORS
	size_t count;
	const struct driver_details *d;

	for (count = 0; count < drivers_count; count++) {
		d = drivers_table[count];
		d->callback();
	}
#else
#  error "unsupported driver iteration approach"
#endif
}
