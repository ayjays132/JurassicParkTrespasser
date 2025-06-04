#include "VR.hpp"
#ifdef ENABLE_MODERN_ENV_RENDER
#include "Lib/Renderer/EnvironmentModern.hpp"
#endif
#include <cstdio>

namespace VR {

bool Initialize(const char* envCubemapFolder) {
    // Placeholder for Oculus Quest initialization
    std::printf("VR Initialize stub\n");
#ifdef ENABLE_MODERN_ENV_RENDER
    if(envCubemapFolder)
        Renderer::InitializeEnvironment(envCubemapFolder);
    else
        Renderer::InitializeEnvironment("assets/env");
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
