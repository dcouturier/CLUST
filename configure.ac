AC_INIT([clust], 0.1)
AC_CONFIG_AUX_DIR([config])
AM_INIT_AUTOMAKE([foreign dist-bzip2])
AC_CONFIG_MACRO_DIR([config])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

LT_INIT

AC_CHECK_HEADERS([ \
	sys/types.h unistd.h fcntl.h strings.h pthread.h time.h \
	errno.h stdarg.h limits.h signal.h stdlib.h
])

AC_CHECK_LIB(pthread, pthread_create)

PKG_PROG_PKG_CONFIG

AC_ARG_ENABLE([ust],
  [AS_HELP_STRING([--disable-ust],
    [disable ust])],
  [ust_support=$enableval], [ust_support=yes])

AS_IF([test "x$ust_support" == "xyes"], [
  PKG_CHECK_MODULES([UST], [lttng-ust,liburcu-bp], [],
	[AC_MSG_ERROR([Cannot find lttng ust library with pkg-config])])
])

AM_CONDITIONAL([HAVE_UST], [test "x$ust_support" == "xyes"])

# be silent by default
AC_PROG_LIBTOOL
AC_PROG_CC
AM_PROG_CC_C_O
AC_CONFIG_FILES([Makefile
    src/Makefile
])

AC_OUTPUT
