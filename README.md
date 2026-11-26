# MHAA Watchdog Core

Use `Watchdog` to arm reset mode or request another supported mode, then service the watchdog at an allowed instant. Where disable is available, bind the capability explicitly.

Check `arm_reset` or `configure`, then service at a target-permitted time. Construct with `DisableControl&` to use the optional disable method.

## Use in an application

Add this repository's `include/` and the matching `watchdog-contract/include/` to the C++11 include path. Include `<watchdog/watchdog.hpp>` and supply a live implementation of the matching Contract. The Core borrows it. In a future device composition, Devices will select the concrete Adapter and wire it to the Core.

- [Technical guide](docs/index.md)
- [Core usage](docs/api.md)
- [Portability and limits](docs/compatibility.md)
- [Worked example and build commands](docs/examples.md)
- [MIT License](LICENSE)

## Generate the API reference

Use Doxygen 1.18.0. From this repository root, create `build/` if it does not exist, then run `doxygen Doxyfile`.

```sh
mkdir -p build
doxygen Doxyfile
```

On PowerShell, use `New-Item -ItemType Directory -Force build` for the first command. Open `build/docs/html/index.html`. Mermaid diagrams render in a browser with access to the Mermaid CDN. GitHub Pages publication runs on published releases and on manual dispatches from `main` once Pages is enabled.
