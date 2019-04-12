#define OFONO_API_SUBJECT_TO_CHANGE
#include <ofono/plugin.h>
#include <ofono/log.h>

#include "dbus-iface.h"

static int example_binder_plugin_init()
{
    ofono_info("Hello example ofono plugin.");
    if(register_example_dbus() != 0) {
        ofono_info("Register example dbus interface.");
    } else {
        ofono_warn("Fail register dbus interface.");
    }
    return 0;
}

static void example_binder_plugin_exit()
{
    free_example_dbus();
    ofono_info("Bye bye example ofono plugin");
}

OFONO_PLUGIN_DEFINE(example, "example plugin",
    OFONO_VERSION, OFONO_PLUGIN_PRIORITY_DEFAULT,
    example_binder_plugin_init, example_binder_plugin_exit)
