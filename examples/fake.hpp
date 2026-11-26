#ifndef MHAA_WATCHDOG_EXAMPLE_FAKE_HPP
#define MHAA_WATCHDOG_EXAMPLE_FAKE_HPP

#include <watchdog/controller.hpp>
#include <watchdog/disable_control.hpp>

namespace example
{
    using namespace mhaa::watchdog;

    class Fake final : public DisableControl
    {
    public:
        Status configure(uint32_t timeout_ms, Mode mode) override
        {
            if (mode != Mode::Reset || timeout_ms != 2000)
            {
                return Status::Unsupported;
            }
            armed = true;
            return Status::Success;
        }
        Status service() override
        {
            if (!armed || !window_open)
            {
                return Status::Locked;
            }
            ++services;
            return Status::Success;
        }
        Status disable() override
        {
            armed = false;
            return Status::Success;
        }

        bool armed = false;
        bool window_open = false;
        unsigned services = 0;
    };
}

#endif
