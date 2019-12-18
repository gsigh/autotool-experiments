ACLOCAL_AMFLAGS = -I m4

# Create a library which contains the drivers' code.
noinst_LTLIBRARIES = src/libdrivers.la
src_libdrivers_la_SOURCES = src/driver_1.c src/driver_2.c
DRIVERS_LIBRARY = src/libdrivers.la
DRIVERS_LDSCRIPT = $(srcdir)/src/drivers.ld

# Create an application which includes the iteration logic and
# uses the library with the drivers' code.
bin_PROGRAMS = app_static
app_static_SOURCES = src/app_main.c src/drivers.c
app_static_LDADD = $(DRIVERS_LIBRARY)
app_static_LDFLAGS = -Wl,-T,$(DRIVERS_LDSCRIPT)
EXTRA_app_static_DEPENDENCIES = $(DRIVERS_LDSCRIPT)
