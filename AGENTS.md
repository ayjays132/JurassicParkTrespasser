# AGENT INSTRUCTIONS

This repository contains the source code for Jurassic Park: Trespasser. The project can be built on Windows and Linux using CMake. Support for Oculus Quest VR is available via a minimal stub implementation.

## Contribution Guidelines

* **Commit Messages**: Follow the format described in `.github/commit_guidelines.txt`.
* **Code Style**: Preserve existing formatting and naming conventions. Prefer explicit, self‐descriptive identifiers.
* **Programmatic Checks**: After modifying C++ code, run
  ```
  cmake -S jp2_pc -B build && cmake --build build
  ```
  Fix any compile errors before committing. If dependencies are missing in the environment you may skip the build but mention it in the PR.

## Porting to Oculus Quest

The project includes placeholder VR support under `Source/Lib/VR`. To enable VR when configuring with CMake use:

```
-DENABLE_OCULUS_QUEST_SUPPORT=ON
```

For a modern look, also enable the environment renderer:

```
-DENABLE_MODERN_ENV_RENDER=ON
```

Provide a folder with six cubemap textures when initialising the VR system. See `Source/Lib/VR/README.md` for details.

Existing assets can be reused. The renderer exposes runtime controls via `Renderer::SetEnvironmentIntensity()` and `Renderer::SetEnvironmentRotation()`.

## Recommended Workflow

1. Generate the build files:
   - Windows: run `Generate-VS2019-x86.cmd`.
   - Other platforms: `cmake -S jp2_pc -B build`.
2. Build the solution via Visual Studio or `cmake --build build`.
3. Test the VR stub by launching `trespass.exe` from the Trespasser game directory.

