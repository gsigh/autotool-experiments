AC_INIT([driverlist], [0.01], [author@example.com], [driverlist], [http://homepage.example.com])
AC_PREREQ([2.68])
AC_CONFIG_SRCDIR([src/app_main.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([1.11 -Wall -Werror subdir-objects])
AC_CONFIG_FILES([Makefile])
AC_PROG_INSTALL
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CXX
AM_PROG_AR
LT_INIT

AC_ARG_ENABLE([driver1], [AS_HELP_STRING([--enable-driver1], [include driver1 [default=yes]])], [], [enable_driver1=yes])
AC_ARG_ENABLE([driver2], [AS_HELP_STRING([--enable-driver2], [include driver2 [default=yes]])], [], [enable_driver2=yes])
AC_ARG_ENABLE([driver3], [AS_HELP_STRING([--enable-driver3], [include driver3 [default=yes]])], [], [enable_driver3=yes])
AM_CONDITIONAL([DRIVER_1], [test "x$enable_driver1" = xyes])
AM_CONDITIONAL([DRIVER_2], [test "x$enable_driver2" = xyes])
AM_CONDITIONAL([DRIVER_3], [test "x$enable_driver3" = xyes])
AS_IF([test -n "$enable_driver1"], [DRIVER_1=$enable_driver1], [DRIVER_1=yes])
AS_IF([test -n "$enable_driver2"], [DRIVER_2=$enable_driver2], [DRIVER_2=yes])
AS_IF([test -n "$enable_driver3"], [DRIVER_3=$enable_driver3], [DRIVER_3=yes])
cat >&AS_MESSAGE_FD <<_EOF
Enabled drivers:
- driver 1 ..... $DRIVER_1
- driver 2 ..... $DRIVER_2
- driver 3 ..... $DRIVER_3
_EOF

AC_OUTPUT
