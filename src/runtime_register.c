#include <stdint.h>
#include <stdlib.h>

#include "runtime_register.h"

/*
 * This approach unfortunately involves a compile time constant upper
 * limit for the number of available drivers. The registration calls are
 * done before main() from "constructors", it's yet to get determined if
 * malloc(3) is available at this time (universally, on all platforms
 * that are supported by sigrok).
 *
 * It's an implementation detail to count the number of overflows and to
 * communicate these conditions to calling application code. Those can
 * raise a warning.
 */
#define DRIVERS_MAX_COUNT 10

#ifndef ARRAY_SIZE
#  define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))
#endif

static struct driver_details const *drivers_table[DRIVERS_MAX_COUNT];
static size_t drivers_count;
static int drivers_exceed;

void runtime_register_driver(const struct driver_details *details) {

	if (drivers_count == ARRAY_SIZE(drivers_table)) {
		drivers_exceed++;
		return;
	}
	drivers_table[drivers_count++] = details;
}

void runtime_iterate_drivers(driver_iter_cb cb_func, void *cb_data) {
	size_t count;

	/* List all successfully registered drivers. */
	for (count = 0; count < drivers_count; count++) {
		cb_func(drivers_table[count], cb_data);
	}

	/* Communicate how many failed to register. */
	for (count = 0; count < drivers_exceed; count++) {
		cb_func(NULL, cb_data);
	}
}
