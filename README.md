# Jurassic Park: Trespasser
A git-based fork of the Jurassic Park: Trespasser source code.

## Discord Server
#### Click the banner or link below to join the server
<p align="center">
  <a href="https://discord.gg/5EngSvu">
  <img src="https://github.com/GamerDude27/JurassicParkTrespasser/blob/master/images/JPT_DiscordServer.png">
  </a>
</p>
<p align="center">Link: https://discord.gg/5EngSvu</p>

## Solution Overview
| Projects          | Generates                         | Notes:                                                                                                                                                                                                                 |
| :---------------- | :-------------------------------- | :--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| AI                | Artificial Intelligence subsystem | A lot of code unused since most traits had to be disabled.                                                                                                                                                             |
| AI Test           | JP2_PC.exe                        | A standalone program allowing to test AI with graphics.                                                                                                                                                                |
| Audio             | Audio.lib                         | The audio sub-system static library featuring the "real-time Foley".                                                                                                                                                   |
| Bug               | Bugs.exe                          | A project concentrating all compiler errors. Since the team switched from VS4 to VS4.1 to VS4.2 to VS6.0 it was useful                                                                                                 |
| CollisionEditor   | CollisionEditor.exe               | Sound effects editor to test the audio engine (very powerful at the time)                                                                                                                                              |
| EntityDBase       | EntityDBase.lib                   | Classes representing all objects in the game.                                                                                                                                                                          |
| File              | File.lib                          | Abstraction classes for File and Images used to build the Groff archives.                                                                                                                                              |
| File Test	        | File	                            | Test for the file and image abstractions.                                                                                                                                                                              |
| Game              | Game.lib	                        | Glue, triggers, Player, Gun classes.                                                                                                                                                                                   |
| GeomDBase         | GeomDBase.lib                     | The 3D representation (Geometry) of all objects defined in EntityDBase.                                                                                                                                                |
| GroffBuild        | GroffBuild.exe                    | The tool in charge of gathering all game assets (3D, sounds, maps) in one GOFF file.                                                                                                                                   |
| GroffExp          | GroffExp.dle	                    | The DLL loaded by 3DS Max that export all data to GOFF sections. This was originally outsourced to another dev and is standalone.                                                                                      |
| GUIApp            | GUIApp.exe                        | A wrapper around the game. The GUI allows changing the game values at runtime for testing. Like the console allowing to change the CVAR in Quake engines.                                                              |
| Loader            | Loader.lib                        | The library loading GOFF assets to RAM.                                                                                                                                                                                |
| Math              | Math.lib                          | The math library (features a fInvSqrt that is not as good as Quake III's InvSqrt since it uses a lookup table but also uses Newton-Raphson).                                                                           |
| Math Test         | MathTest.exe                      | A few functions to test the speed of the math routines.                                                                                                                                                                |
| Physics           | Physics.lib                       | The pelvis heavy, penalty force-based Physic engine library.                                                                                                                                                           |
| PhysicsTest       | PhysicsTest.exe                   | A sandbox level where physic can be tested.                                                                                                                                                                            |
| PipeLineTest      | PipeLineTest.exe                  | Testbed for the rendering pipeline                                                                                                                                                                                     |
| Processor         | Processor.dll                     | Uses CPUID to detect 8086, 80286, 28386 or a 80486, Pentium, K6-3and K7, Detect Floating Point Unit and CPU speed. Loaded at runtime by System project in order to set automatically details level (based on CPU Mhz). |
| QuantizerTool     |	QuantizerTool.exe                 | Aborted project. Does nothing.                                                                                                                                                                                         |
| Render3D          | Render3D.lib                      | The hybrid software/Direct3D renderer.                                                                                                                                                                                 |
| ScreenRenderDWI   |	ScreenRenderDWI.lib               | Pentium, PentiumPro and K6_3D specific code ASM optimized code for scanline and cache rendering. Direct3D code.                                                                                                        |
| Std               |	Std.lib                           | Extension of STL. A horrible mess of specific containers of containers of set of hashmap. Arg.                                                                                                                         |
| System            | System.lib                        | Contains scheduler, Virtual Memory. Thread control. SetupForSelfModifyingCode (via modifying the page tables associated with the application). Many things are not used.                                               |
| trespass          | trespass.exe                      | The game we played.                                                                                                                                                                                                    |
| View              | View.lib                          | Raster to window code. Blitter, DirectDraw, Direct3D, software palette viewers.                                                                                                                                        |
| WaveTest          | WaveTest.exe                      | Shell to test wave modeling.                                                                                                                                                                                           |
| WinShell          | WinShell.lib                      | win32 windows creation and management library                                                                                                                                                                          |

## Production Pipeline
<p align="center">
  <img src="https://github.com/GamerDude27/JurassicParkTrespasser/blob/master/images/ProductionPipeline.png">
</p>

#

Sanglard, F. (2014). "Solution Overview" [list] & "Production Pipeline" [image].  
Available at: http://fabiensanglard.net/trespasser [Accessed 17 Oct. 2018].

## Oculus Quest Support
A minimal VR stub can be enabled via `ENABLE_OCULUS_QUEST_SUPPORT` when configuring with CMake. This is the starting point for an Android/Quest port.

## Modern Environment Rendering
The project ships with a simple OpenGL based environment renderer supporting
physically based shading. It draws a cubemap skybox and is compatible with both
desktop and Oculus Quest builds. Enable it with the
`ENABLE_MODERN_ENV_RENDER` option and provide a folder containing six cubemap
textures when initialising the VR system. If the OpenGL and GLEW development
packages are not available, the build automatically falls back to a stub
implementation so compilation can succeed without OpenGL.

The renderer exposes basic controls for VR integration. Use
`Renderer::SetEnvironmentIntensity()` to adjust brightness and
`Renderer::SetEnvironmentRotation()` to orient the cubemap dynamically.

## SDL Game Controller Input
Desktop builds optionally support modern game controllers via SDL2.
Enable the feature with the `USE_SDL_CONTROLLER` CMake option. When
enabled the System library links against SDL2 and `CInput` will query
connected gamepads for movement and basic button actions. `VR::GetControllerInput`
shares the same mappings so controllers behave consistently in VR.
The default bindings are:

- **A** &rarr; `Use`
- **B** &rarr; `Stow`
- **X** &rarr; `Grab`
- **Y** &rarr; `Jump`
- **Left Shoulder** &rarr; `Control`
- **Right Shoulder** &rarr; `Shift`

## Building on Linux

Trespasser is a Windows application. On Linux you can build a Windows
executable using the mingw-w64 cross compiler. Install the cross
toolchain and configure CMake with `CMAKE_SYSTEM_NAME` set to `Windows`
and the mingw compilers:

```bash
cmake -S jp2_pc -B build \
  -DCMAKE_SYSTEM_NAME=Windows \
  -DCMAKE_C_COMPILER=x86_64-w64-mingw32-gcc \
  -DCMAKE_CXX_COMPILER=x86_64-w64-mingw32-g++ \
  -DCMAKE_RC_COMPILER=x86_64-w64-mingw32-windres
cmake --build build
```

This produces the same Windows binaries as the Visual Studio build.

## Android Build Setup

The Android port uses the official Android NDK. Install version r21 or newer via
Android Studio or from the [NDK downloads](https://developer.android.com/ndk/).
After installation set the `ANDROID_NDK` environment variable to the NDK root
before invoking CMake.

Generate the Android project using the provided script:

```bash
cmake -S android -B build-android \
  -DANDROID_NDK="$ANDROID_NDK" \
  -DENABLE_OCULUS_QUEST_SUPPORT=ON \
  -DENABLE_MODERN_ENV_RENDER=ON
```

Build the shared library with:

```bash
cmake --build build-android
```

The resulting `libjpt_android.so` can then be packaged into an APK along with
the assets copied by CMake.

