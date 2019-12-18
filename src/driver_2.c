#include <stdio.h>
#include "drivers.h"

static void local_func(void) __attribute__((used));
static void local_func(void)
{
	printf("driver2, do something");
}

DECLARE_DRIVER(driver2, 2)
