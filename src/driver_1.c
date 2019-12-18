#include <stdio.h>
#include "drivers.h"

static void local_func(void) __attribute__((used));
static void local_func(void)
{
	printf("driver1, do something\n");
}

DECLARE_DRIVER(driver1, 1)
