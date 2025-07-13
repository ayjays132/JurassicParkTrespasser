/*******************************************************************************
 * Oculus Quest VR stub interface.
 *******************************************************************************/
#ifndef HEADER_LIB_VR_VR_HPP
#define HEADER_LIB_VR_VR_HPP

#ifdef ENABLE_OCULUS_QUEST_SUPPORT
#include "Lib/Renderer/EnvironmentModern.hpp"
#include <GLES3/gl3.h>
#endif
#include "Lib/Control/Control.hpp"

namespace VR {

// Provide the path to a cubemap folder when initialising so the modern
// environment renderer can load the textures.
    // Optionally specify an initial cubemap folder and brightness when
    // initialising the VR system. The intensity parameter is passed directly
    // to the modern environment renderer when available.
    // Returns true on success. When Quest support is enabled the value
    // reflects whether the modern environment renderer initialised
    // correctly.
    bool Initialize(const char *envCubemapFolder = nullptr,
                    float envIntensity = 1.0f);
    void Shutdown();
    void BeginFrame();
    void EndFrame();

// Adjust the environment brightness. Values above 1.0 brighten the cubemap
// while values below 1.0 darken it. Has no effect when the modern renderer
// is not available.
void SetEnvironmentIntensity(float intensity);

// Apply a rotation matrix to the environment cubemap. Rotation should be a
// 4x4 column-major matrix. Does nothing on stub builds.
void SetEnvironmentRotation(const float rotation[16]);

// Retrieve input from VR controllers when available.
SInput GetControllerInput();

} // namespace VR

#endif // HEADER_LIB_VR_VR_HPP
