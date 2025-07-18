# VR Stub

This directory contains placeholder code for Oculus Quest support. The implementation logs initialization and shutdown messages.

A basic Android-specific implementation is provided in `android/VR_Android.cpp`. It uses `android/log.h` to output messages when running on an Android-based headset such as the Oculus Quest.

To build for Android enable the `ENABLE_OCULUS_QUEST_SUPPORT` option and use an Android toolchain with CMake. The library will compile the Android stub automatically when the `ANDROID` variable is set.

### Environment Renderer
The optional modern environment renderer (`ENABLE_MODERN_ENV_RENDER`) now loads
a cubemap using OpenGL and draws it each frame. Pass the cubemap folder and an
optional intensity value to `VR::Initialize()` when starting the application.
`VR::Initialize()` returns **false** if the cubemap or shaders fail to load,
allowing callers to detect when the renderer is unavailable.
If the required OpenGL
development libraries are not present the build instead compiles a stub and the
environment will not be rendered. The environment intensity and orientation can
be adjusted at runtime via `VR::SetEnvironmentIntensity()` and
 `VR::SetEnvironmentRotation()` whenever the renderer is available.
Shader compilation and program linking errors are now reported to the console
to aid debugging when OpenGL is used.

### Controller Input
`VR::GetControllerInput()` returns an `SInput` struct describing the state of any
connected VR controllers. When built with `USE_SDL_CONTROLLER` enabled the stub
also queries standard gamepads via SDL and maps buttons to common commands:

- **A** &rarr; `uCMD_USE`
- **B** &rarr; `uCMD_STOW`
- **X** &rarr; `uCMD_GRAB`
- **Y** &rarr; `uCMD_JUMP`
- **Left Shoulder** &rarr; `uCMD_CONTROL`
- **Right Shoulder** &rarr; `uCMD_SHIFT`

If controller support is unavailable the function simply returns a zeroed
structure.

