#include "EnvironmentModern.hpp"
#include <cstdio>
#ifdef __ANDROID__
#include <android/log.h>
#endif

namespace Renderer {

bool InitializeEnvironment() {
#ifdef __ANDROID__
    __android_log_print(ANDROID_LOG_INFO, "Trespasser", "Modern environment renderer init");
#else
    std::printf("Modern environment renderer init\n");
#endif
    return true;
}

void ShutdownEnvironment() {
#ifdef __ANDROID__
    __android_log_print(ANDROID_LOG_INFO, "Trespasser", "Modern environment renderer shutdown");
#else
    std::printf("Modern environment renderer shutdown\n");
#endif
}

void RenderEnvironment() {
    // Placeholder for PBR environment rendering
}

} // namespace Renderer
