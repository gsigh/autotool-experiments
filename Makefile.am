ACLOCAL_AMFLAGS = -I m4

# Create a library which contains the drivers' code.
noinst_LTLIBRARIES = src/libdrivers.la
src_libdrivers_la_SOURCES = src/driver_1.c src/driver_2.c
DRIVERS_LIBRARY = src/libdrivers.la
DRIVERS_LDSCRIPT = $(srcdir)/src/drivers.ld

# Create a library which contains the drivers' code, as well as
# the list of included drivers, and iteration logic for the list.
noinst_LTLIBRARIES += src/libdrivers_list.la
src_libdrivers_list_la_SOURCES = src/drivers.c
src_libdrivers_list_la_LIBADD = src/libdrivers.la
src_libdrivers_list_la_LDFLAGS = -Wl,-T,$(DRIVERS_LDSCRIPT)
EXTRA_src_libdrivers_list_la_DEPENDENCIES = $(DRIVERS_LDSCRIPT)
src_libdrivers_list_la_AR = echo HELLO $(LD) -r -o
src_libdrivers_list_la_LIBTOOLFLAGS = --no-quiet
DRIVERS_LIST_LIBRARY = src/libdrivers_list.la

# Create an application which uses the iterating library.
bin_PROGRAMS = app_static
app_static_SOURCES = src/app_main.c
app_static_LDADD = $(DRIVERS_LIST_LIBRARY)
app_static_LDFLAGS = -Wl,-T,$(DRIVERS_LDSCRIPT)
EXTRA_app_static_DEPENDENCIES = $(DRIVERS_LDSCRIPT)
