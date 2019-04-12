#define OFONO_API_SUBJECT_TO_CHANGE
#include <ofono/plugin.h>
#include <ofono/log.h>

static int example_binder_plugin_init()
{
    ofono_info("Hello example ofono plugin.");
    return 0;
}

static void example_binder_plugin_exit()
{
    ofono_info("Bye bye example ofono plugin");
}

OFONO_PLUGIN_DEFINE(example, "example plugin",
    OFONO_VERSION, OFONO_PLUGIN_PRIORITY_DEFAULT,
    example_binder_plugin_init, example_binder_plugin_exit)
