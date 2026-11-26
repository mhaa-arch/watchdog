#include <watchdog/watchdog.hpp>
#include "fake.hpp"

using namespace mhaa::watchdog;
using namespace example;

int main()
{
    Fake controller;
    Watchdog watchdog(controller);
    if (watchdog.arm_reset(2000) != Status::Success)
    {
        return 1;
    }
    controller.window_open = true;
    return watchdog.service() == Status::Success ? 0 : 1;
}
