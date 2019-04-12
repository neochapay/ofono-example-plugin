#include <ofono/dbus.h>
#include <ofono/gdbus.h>

#define EXAMPLE_DBUS_INTERFACE "org.nemomobile.ofono.Example"

static const GDBusMethodTable example_dbus_methods[] = {};
static const GDBusSignalTable example_dbus_signals[] = {};

/*
If you call in console 

#dbus-send --system --print-reply --dest=org.ofono / org.freedesktop.DBus.Introspectable.Introspect

you can see - we are regestry /Example interface. But if we call methods of this interface

#dbus-send --system --print-reply --dest=org.ofono /Example org.freedesktop.DBus.Introspectable.Introspect

We get error becouse we don;'t have any methods ^_^

*/

int register_example_dbus() {
    DBusConnection *connection = dbus_connection_ref(ofono_dbus_get_connection());

    if (g_dbus_register_interface(connection, "/Example",
				EXAMPLE_DBUS_INTERFACE,
				example_dbus_methods,
				example_dbus_signals,
				NULL, NULL, NULL)) {
	    return 1;
    }

    return 0;
}

void free_example_dbus() {

}
