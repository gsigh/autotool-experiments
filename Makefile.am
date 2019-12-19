ACLOCAL_AMFLAGS = -I m4

# Create a library which contains the drivers' code.
DRIVERS_LIBRARY = src/libdrivers.la
noinst_LTLIBRARIES = $(DRIVERS_LIBRARY)
src_libdrivers_la_SOURCES = src/driver_1.c src/driver_2.c src/drivers.h

# Create a library which contains the drivers' code, as well as
# the list of included drivers, and iteration logic for the list.
DRIVERS_LDSCRIPT = $(srcdir)/src/drivers.ld
DRIVERS_LIST_LIBRARY = src/libdrivers_list.la
noinst_LTLIBRARIES += $(DRIVERS_LIST_LIBRARY)
src_libdrivers_list_la_SOURCES = src/drivers.c
src_libdrivers_list_la_LIBADD = src/libdrivers.la
src_libdrivers_list_la_LDFLAGS = -Wl,-T,$(DRIVERS_LDSCRIPT)
EXTRA_src_libdrivers_list_la_DEPENDENCIES = $(DRIVERS_LDSCRIPT)
src_libdrivers_list_la_AR = echo HELLO $(LD) -r -o
EXTRA_DIST = $(DRIVERS_LDSCRIPT)
src_libdrivers_list_la_LIBTOOLFLAGS = --no-quiet

## interactive example, uses libtool without automake
## $ libtool --no-quiet --mode=link gcc -o drivers_list.o src/driver_1.lo src/driver_2.lo src/src_libdrivers_list_la-drivers.lo ../src/drivers.ld
## libtool: link: /usr/bin/ld -m elf_x86_64 -r -o drivers_list.o  src/.libs/driver_1.o src/.libs/driver_2.o src/.libs/src_libdrivers_list_la-drivers.o
## what the? runs ld(1) which is good, but ignores the specified .ld script which is essential! neither -T file nor -Wl,-T,file change this :(

# Create a library with additional support code (communication).
COMM_LIBRARY = src/libcomm.la
noinst_LTLIBRARIES += $(COMM_LIBRARY)
src_libcomm_la_SOURCES = src/comm.c src/comm.h

# Create an application which uses the iterating library.
bin_PROGRAMS = app_static
app_static_SOURCES = src/app_main.c
app_static_LDADD = $(DRIVERS_LIST_LIBRARY)
app_static_LDFLAGS = -Wl,-T,$(DRIVERS_LDSCRIPT)
app_static_LDADD += $(COMM_LIBRARY)
EXTRA_app_static_DEPENDENCIES = $(DRIVERS_LDSCRIPT)
