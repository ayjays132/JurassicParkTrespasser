#include "EnvironmentModern.hpp"

namespace Renderer {

bool InitializeEnvironment(const char*) {
    // Stub initialization when OpenGL is unavailable
    return true;
}

void ShutdownEnvironment() {
    // Nothing to clean up in the stub
}

void RenderEnvironment(const float[16], const float[16]) {
    // Stub does not draw anything
}

void SetEnvironmentIntensity(float) {
    // Intensity adjustment ignored in stub
}

void SetEnvironmentRotation(const float[16]) {
    // Rotation ignored in stub
}

} // namespace Renderer
