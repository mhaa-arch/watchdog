# Use the Watchdog Core

Public entry headers are [watchdog/watchdog.hpp](../include/watchdog/watchdog.hpp).

## Arm and service separately

Construct `Watchdog` from a live `Controller&`. `arm_reset` selects reset mode, and `configure` accepts a mode explicitly. The Core rejects zero before forwarding a request. Check the returned status. Neither operation services the watchdog.

Call `service` only at an instant allowed by the target. If the composition supplies `DisableControl&`, use that constructor to expose disable. The base binding returns `Unsupported` for a disable request.

## Composition and lifetime

Application code calls the Watchdog Core. It borrows the matching Contract, which an Adapter implements using its Hardware Definitions. Future Devices will create or bind these objects and establish their lifetime. To use the examples today, construct the facade directly with the supplied fake. Keep each borrowed resource alive for its use by the facade and follow the Adapter's access and synchronization requirements.
