#include "VR.hpp"
#ifdef ENABLE_MODERN_ENV_RENDER
#include "Lib/Renderer/EnvironmentModern.hpp"
#include <cmath>
#endif
#include <cstdio>

namespace VR {

bool Initialize(const char* envCubemapFolder) {
    // Placeholder for Oculus Quest initialization
    std::printf("VR Initialize stub\n");

#ifdef ENABLE_MODERN_ENV_RENDER
    if (envCubemapFolder) {
        Renderer::InitializeEnvironment(envCubemapFolder);
    } else {
        Renderer::InitializeEnvironment("assets/env");
    }
    Renderer::SetEnvironmentIntensity(1.0f);
#endif

    return true;
}

void Shutdown() {
    // Placeholder cleanup
    std::printf("VR Shutdown stub\n");

#ifdef ENABLE_MODERN_ENV_RENDER
    Renderer::ShutdownEnvironment();
#endif
}

void BeginFrame() {
    // Placeholder per-frame begin
#ifdef ENABLE_MODERN_ENV_RENDER
    static float angle = 0.0f;
    angle += 0.01f;
    float c = std::cos(angle);
    float s = std::sin(angle);
    float rot[16] = {
        c, 0, s, 0,
        0, 1, 0, 0,
       -s, 0, c, 0,
        0, 0, 0, 1
    };
    Renderer::SetEnvironmentRotation(rot);
#endif
}

void EndFrame() {
    // Placeholder per-frame end
#ifdef ENABLE_MODERN_ENV_RENDER
    float identity[16] = {
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        0,0,0,1
    };
    Renderer::RenderEnvironment(identity, identity);
#endif
}

} // namespace VR
