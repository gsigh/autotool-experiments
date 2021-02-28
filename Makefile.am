ACLOCAL_AMFLAGS = -I m4

# Remove the tedium of keeping track whether an automake variable
# previously was assigned to, and whether = or += _must_ be used.
# Start empty, and always append.
bin_PROGRAMS =
noinst_LTLIBRARIES =
lib_LTLIBRARIES =

# Create a library which contains the drivers' code. Including the
# support to enumerate the list of available drivers.
DRIVERS_LIBRARY = src/libdrivers.la
noinst_LTLIBRARIES += $(DRIVERS_LIBRARY)
src_libdrivers_la_SOURCES = src/drivers.c src/drivers.h
if DRIVER_1
src_libdrivers_la_SOURCES += src/driver_1.c
endif
if DRIVER_2
src_libdrivers_la_SOURCES += src/driver_2.c
endif
if DRIVER_3
src_libdrivers_la_SOURCES += src/driver_3.c
endif

# Create a library for typical application tasks. Also include the
# above drivers library in the application tasks library, such that
# applications need not care about the internal implementation.
COMBO_LIBRARY = src/libcombo.la
lib_LTLIBRARIES += $(COMBO_LIBRARY)
src_libcombo_la_SOURCES = src/comm.c src/comm.h
src_libcombo_la_LDFLAGS = -version-info 1:2:0
# TODO Linking the combo library to the drivers library currently
# doesn't work. Still need to find the proper automake syntax. Or
# just links the app to both libraries. Or just compile drivers in
# the "combo" library. After all the separation of the drivers lib
# was an internal libsigrok detail to begin with.
## src_libcombo_la_LDADD = $(DRIVERS_LIBRARY)

# Create an application which uses the combined library.
bin_PROGRAMS += app_combo
app_combo_SOURCES = src/app_main.c
app_combo_LDADD = $(DRIVERS_LIBRARY) $(COMBO_LIBRARY)
