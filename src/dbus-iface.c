#include <ofono/dbus.h>
#include <ofono/gdbus.h>
#include <ofono/log.h>

#define EXAMPLE_DBUS_INTERFACE "org.nemomobile.ofono.Example"

static DBusMessage *example_meow(DBusConnection *conn, DBusMessage *msg, void *data) {
    const char *name;
    const char *talk;

    dbus_message_get_args(msg, NULL, DBUS_TYPE_STRING, &name,
                                     DBUS_TYPE_STRING, &talk,
                                     DBUS_TYPE_INVALID);

    ofono_info("Cat %s say %s !", name, talk);
    return dbus_message_new_method_return(msg);
}

static const GDBusMethodTable example_dbus_methods[] = {
    { GDBUS_METHOD("SayMeow", GDBUS_ARGS({"name", "s"}, {"talk", "s"}), NULL, example_meow) },
    { }
};

static const GDBusSignalTable example_dbus_signals[] = {};

/*
If you call in console 

dbus-send --system --print-reply --dest=org.ofono /Example org.nemomobile.ofono.Example.SayMeow string:"Tom" string:"meow"

You can se in debug ofono log message "Cat Tom say meow !"
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

