#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "drivers.h"

/*
 * The runtime registration approach. Assumes that registering drivers
 * provide the list node storage, and that this is the only use of this
 * memory.
 */

static struct driver_list_node *driver_list_head;
static struct driver_list_node **driver_list_tail = &driver_list_head;
static size_t driver_list_size;

void register_driver(struct driver_list_node *node) {

	if (!node)
		return;
	node->next = NULL;

	*driver_list_tail = node;
	driver_list_tail = &node->next;
	driver_list_size++;
}

void iterate_drivers(void)
{
	struct driver_list_node *node;
	const struct driver_details *d;

	printf("items:\n");
	for (node = driver_list_head; node; node = node->next) {
		d = node->driver;
		if (!d)
			continue;
		printf(" %p %d %s %p\n", d,
			d->identification, d->label, d->callback);
	}
	printf("list end\n");
}

void execute_drivers(void)
{
	struct driver_list_node *node;
	const struct driver_details *d;

	for (node = driver_list_head; node; node = node->next) {
		d = node->driver;
		if (!d)
			continue;
		d->callback();
	}
}
