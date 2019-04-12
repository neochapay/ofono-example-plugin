AC_INIT([example-plugin], [0,1])
AC_CONFIG_SRCDIR(src/example-plugin.c)
AM_INIT_AUTOMAKE
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LIBTOOL

AC_ENABLE_SHARED
AC_DISABLE_STATIC


PKG_CHECK_MODULES(DBUS, dbus-1 >= 1.4, dummy=yes,
		AC_MSG_ERROR(D-Bus >= 1.4 is required))
AC_SUBST(DBUS_CFLAGS)
AC_SUBST(DBUS_LIBS)

PKG_CHECK_MODULES(GLIB, glib-2.0 >= 2.32, dummy=yes,
		AC_MSG_ERROR(GLib >= 2.32 is required))
AC_SUBST(GLIB_CFLAGS)
AC_SUBST(GLIB_LIBS)

PKG_CHECK_MODULES(DBUS_GLIB, dbus-glib-1, dummy=yes,
		AC_MSG_ERROR(dbus-glib is required))
AC_SUBST(DBUS_GLIB_CFLAGS)
AC_SUBST(DBUS_GLIB_LIBS)

libdir=/usr/lib/ofono/plugins

AC_OUTPUT(Makefile src/Makefile)
