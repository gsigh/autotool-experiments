#include <stdio.h>
#include "drivers.h"

static void local_func(void)
{
	printf("driver3, do something\n");
}

DECLARE_DRIVER(driver3, 3, local_func);
