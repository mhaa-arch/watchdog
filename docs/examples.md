# Run the Watchdog Core example

The Core borrows a simulated watchdog and requests nominal reset at 2000 ms. The test opens the fake's service window and calls `service` explicitly. The behavior program checks rejected modes, unsupported disable on a base binding and rejection outside the simulated window.

## Example program

The [program](../examples/example.cpp) uses the [local fake](../examples/fake.hpp) to demonstrate injection. A concrete Adapter implementing the same Contract can be supplied to the same facade.

```cpp
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
```

## Build and run

Build from this repository root. Set `contract_include` to the matching Contract's `include/` directory. The value below applies to the MHAA development workspace. Both programs exit with status 0 on success and print no output. On Windows execute `example.exe` and `behavior.exe`.

```sh
contract_include=../../contracts/watchdog-contract/include
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -I"$contract_include" examples/example.cpp -o example
./example
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -I"$contract_include" tests/behavior.cpp -o behavior
./behavior
```

See the [behavior test](../tests/behavior.cpp) for the additional cases described above.
