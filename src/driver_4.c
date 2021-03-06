#include <stdio.h>
#include "drivers.h"

static void local_func(void)
{
	printf("driver4, do something\n");
}

DECLARE_DRIVER(driver4, 4, local_func);
