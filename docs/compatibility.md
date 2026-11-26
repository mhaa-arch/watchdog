# Using Watchdog across targets

The only project dependency is the matching `watchdog-contract`. Keep its API revision aligned with this Core.

The Core leaves the service schedule to the application and composition. Verify timeout tolerance, window opening, reset effects and whether disable is permitted on the target before adopting a schedule.

This repository's host simulations and shared API compile/link checks provide source-level evidence. Target timing and physical behavior require hardware validation.
