# VR Stub

This directory contains placeholder code for Oculus Quest support. The implementation logs initialization and shutdown messages.

A basic Android-specific implementation is provided in `android/VR_Android.cpp`. It uses `android/log.h` to output messages when running on an Android-based headset such as the Oculus Quest.

To build for Android enable the `ENABLE_OCULUS_QUEST_SUPPORT` option and use an Android toolchain with CMake. The library will compile the Android stub automatically when the `ANDROID` variable is set.


### Environment Renderer
The optional modern environment renderer (`ENABLE_MODERN_ENV_RENDER`) enhances visual fidelity with a placeholder physically based pipeline. It integrates with the VR system when Oculus Quest support is enabled.

