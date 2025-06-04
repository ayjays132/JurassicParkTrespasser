# VR Stub

This directory contains placeholder code for Oculus Quest support. The implementation logs initialization and shutdown messages.

A basic Android-specific implementation is provided in `android/VR_Android.cpp`. It uses `android/log.h` to output messages when running on an Android-based headset such as the Oculus Quest.

To build for Android enable the `ENABLE_OCULUS_QUEST_SUPPORT` option and use an Android toolchain with CMake. The library will compile the Android stub automatically when the `ANDROID` variable is set.

### Environment Renderer
The optional modern environment renderer (`ENABLE_MODERN_ENV_RENDER`) now loads
a cubemap using OpenGL and draws it each frame. Pass the cubemap folder to
`VR::Initialize()` when starting the application. The environment intensity and
orientation can be adjusted at runtime via `Renderer::SetEnvironmentIntensity()`
and `Renderer::SetEnvironmentRotation()`.

