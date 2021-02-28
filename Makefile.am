ACLOCAL_AMFLAGS = -I m4

# Remove the tedium of keeping track whether an automake variable
# previously was assigned to, and whether = or += _must_ be used.
# Start empty, and always append.
bin_PROGRAMS =
noinst_LTLIBRARIES =
lib_LTLIBRARIES =

# Create a library for typical application tasks. Also include the
# drivers' implementation as well as the support code to enumerate
# the available drivers. The separation into application code and
# the drivers library (as it was inherited from the libisgrok build)
# has become obsolete.
COMBO_LIBRARY = src/libcombo.la
lib_LTLIBRARIES += $(COMBO_LIBRARY)
src_libcombo_la_SOURCES = src/comm.c src/comm.h
src_libcombo_la_SOURCES += src/drivers.c src/drivers.h
if DRIVER_1
src_libcombo_la_SOURCES += src/driver_1.c
endif
if DRIVER_2
src_libcombo_la_SOURCES += src/driver_2.c
endif
if DRIVER_3
src_libcombo_la_SOURCES += src/driver_3.c
endif
src_libcombo_la_LDFLAGS = -version-info 1:2:0

# Create an application which uses the combined library.
bin_PROGRAMS += app_combo
app_combo_SOURCES = src/app_main.c
app_combo_LDADD = $(COMBO_LIBRARY)
