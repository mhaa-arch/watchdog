#include <watchdog/watchdog.hpp>
#include "../examples/fake.hpp"

#include <cassert>

using namespace mhaa::watchdog;
using namespace example;

int main()
{
    Fake controller;
    Watchdog watchdog(controller);
    assert(watchdog.arm_reset(0) == Status::InvalidArgument);
    assert(watchdog.arm_reset(100) == Status::Unsupported && !controller.armed);
    assert(watchdog.arm_reset(2000) == Status::Success && controller.armed);
    assert(controller.services == 0);
    assert(watchdog.service() == Status::Locked && controller.services == 0);
    controller.window_open = true;
    assert(watchdog.service() == Status::Success && controller.services == 1);
    assert(controller.disable() == Status::Success && watchdog.service() == Status::Locked);

    Watchdog base(static_cast<Controller &>(controller));
    assert(base.disable() == Status::Unsupported);
    assert(watchdog.configure(2000, Mode::Interrupt) == Status::Unsupported);
    assert(watchdog.configure(2000, Mode::Reset) == Status::Success);
    assert(watchdog.disable() == Status::Success && !controller.armed);
}
