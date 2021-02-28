#include <stdio.h>

#include "comm.h"
#include "drivers.h"
#include "runtime_register.h"

static void iter_head(void *cb_data) {

	printf("runtime registered items:\n");
}

static void iter_item(const struct driver_details *driver, void *cb_data) {
	const struct driver_details *d;

	if (!driver) {
		printf("space exceeded\n");
		return;
	}

	d = driver; /* for code re-use */
	printf(" %p %d %s %p\n", d,
			d->identification, d->label, d->callback);
}

static void iter_tail(void *cb_data) {

	printf("runtime registered list end\n");
}

static void exec_head(void *cb_data) {

	printf("runtime registered execution start\n");
}

static void exec_item(const struct driver_details *driver, void *cb_data) {
	const struct driver_details *d;

	if (!driver)
		return;

	driver->callback();
}

static void exec_tail(void *cb_data) {

	printf("runtime registered execution end\n");
}

int main(int argc, char *argv[])
{
	void *cb_data;

	/* List drivers which registered at runtime. */
	cb_data = NULL;
	iter_head(cb_data);
	runtime_iterate_drivers(iter_item, cb_data);
	iter_tail(cb_data);

	/* Do some unspecified application stuff. */
	communicate();

	/* List drivers which were collected at compile time. */
	iterate_drivers();

	/* Execute drivers which were collected at compile time. */
	execute_drivers();

	/* Execute drivers which registered at runtime. */
	cb_data = NULL;
	exec_head(cb_data);
	runtime_iterate_drivers(exec_item, cb_data);
	exec_tail(cb_data);

	return 0;
}
