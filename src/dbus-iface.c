#include <ofono/dbus.h>
#include <ofono/gdbus.h>
#include <ofono/log.h>

#define EXAMPLE_DBUS_INTERFACE "org.nemomobile.ofono.Example"

static DBusMessage *example_meow(DBusConnection *conn, DBusMessage *msg, void *data) {
    ofono_info("Some cat say meow!");
    return dbus_message_new_method_return(msg);
}

static const GDBusMethodTable example_dbus_methods[] = {
    { GDBUS_METHOD("SayMeow", GDBUS_ARGS({"path", "s"}), NULL, example_meow) },
    { }
};

static const GDBusSignalTable example_dbus_signals[] = {};

/*
If you call in console 

dbus-send --system --print-reply --dest=org.ofono /Example org.nemomobile.ofono.Example.SayMeow string:""

You can se in debug ofono log message "Some cat say meow"
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

