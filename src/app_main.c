#include <stdio.h>

#include "comm.h"
#include "drivers.h"

int main(int argc, char *argv[])
{

	communicate();
	iterate_drivers();
	execute_drivers();

	return 0;
}
