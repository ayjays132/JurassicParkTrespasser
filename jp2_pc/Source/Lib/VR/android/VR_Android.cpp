#include "../VR.hpp"
#ifdef __ANDROID__
#include <android/log.h>
#endif
#ifdef ENABLE_OCULUS_QUEST_SUPPORT
#include "Lib/Renderer/EnvironmentModern.hpp"
#include <cmath>
#endif

namespace VR {

bool Initialize(const char *envCubemapFolder, float envIntensity) {
#ifdef __ANDROID__
    __android_log_print(ANDROID_LOG_INFO, "Trespasser", "VR Android Initialize stub");
#endif
#ifdef ENABLE_OCULUS_QUEST_SUPPORT
    bool ok = false;
    if (envCubemapFolder) {
        ok = Renderer::InitializeEnvironment(envCubemapFolder);
    } else {
        ok = Renderer::InitializeEnvironment("assets/env");
    }
    if (!ok) {
#ifdef __ANDROID__
        __android_log_print(ANDROID_LOG_ERROR, "Trespasser", "Failed to initialise environment renderer");
#else
        std::fprintf(stderr, "Failed to initialise environment renderer\n");
#endif
    }
    Renderer::SetEnvironmentIntensity(envIntensity);
    return ok;
#else
    (void)envCubemapFolder;
    (void)envIntensity;
    return true;
#endif
}

void Shutdown() {
#ifdef __ANDROID__
    __android_log_print(ANDROID_LOG_INFO, "Trespasser", "VR Android Shutdown stub");
#endif
#ifdef ENABLE_OCULUS_QUEST_SUPPORT
    Renderer::ShutdownEnvironment();
#endif
}

void BeginFrame() {
#ifdef ENABLE_OCULUS_QUEST_SUPPORT
    static float angle = 0.0f;
    angle += 0.01f;
    float c = std::cos(angle);
    float s = std::sin(angle);
    float rot[16] = {c, 0, s, 0, 0, 1, 0, 0, -s, 0, c, 0, 0, 0, 0, 1};
    Renderer::SetEnvironmentRotation(rot);
#endif
}

void EndFrame() {
#ifdef ENABLE_OCULUS_QUEST_SUPPORT
    float identity[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
    Renderer::RenderEnvironment(identity, identity);
#endif
}

} // namespace VR
