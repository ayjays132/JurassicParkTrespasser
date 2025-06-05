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
bool Initialize(const char *envCubemapFolder = nullptr);
void Shutdown();
void BeginFrame();
void EndFrame();

// Retrieve input from VR controllers when available.
SInput GetControllerInput();

} // namespace VR

#endif // HEADER_LIB_VR_VR_HPP
