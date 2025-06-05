#include "../VR.hpp"
#ifdef __ANDROID__
#include <android/log.h>
#endif

namespace VR {

bool Initialize(const char *, float) {
#ifdef __ANDROID__
    __android_log_print(ANDROID_LOG_INFO, "Trespasser", "VR Android Initialize stub");
#endif
    return true;
}

void Shutdown() {
#ifdef __ANDROID__
    __android_log_print(ANDROID_LOG_INFO, "Trespasser", "VR Android Shutdown stub");
#endif
}

void BeginFrame() {}
void EndFrame() {}

} // namespace VR
