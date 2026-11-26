#ifndef MHAA_WATCHDOG_HPP
#define MHAA_WATCHDOG_HPP

#include <stdint.h>
#include <watchdog/controller.hpp>
#include <watchdog/disable_control.hpp>
#include <watchdog/types.hpp>

namespace mhaa
{
    namespace watchdog
    {
        /** @brief Arms and explicitly services one borrowed watchdog. */
        class Watchdog
        {
        public:
            explicit Watchdog(Controller &watchdog) : watchdog_(watchdog), disable_(nullptr) {}
            explicit Watchdog(DisableControl &watchdog) : watchdog_(watchdog), disable_(&watchdog) {}

            Status configure(uint32_t timeout_ms, Mode mode)
            {
                return timeout_ms ? watchdog_.configure(timeout_ms, mode) : Status::InvalidArgument;
            }

            /** @brief Arms a reset watchdog using a positive nominal period. */
            Status arm_reset(uint32_t timeout_ms)
            {
                return configure(timeout_ms, Mode::Reset);
            }

            /** @brief Services the armed watchdog when the Adapter permits it. */
            Status service() { return watchdog_.service(); }

            Status disable() { return disable_ ? disable_->disable() : Status::Unsupported; }

        private:
            Controller &watchdog_;
            DisableControl *disable_;
        };
    }
}

#endif
