#include <stdio.h>
#include "drivers.h"

static void local_func(void)
{
	printf("driver5, do something\n");
}

DECLARE_DRIVER(driver5, 5, local_func);
