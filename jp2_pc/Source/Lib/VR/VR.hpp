/*******************************************************************************
 * Oculus Quest VR stub interface.
 *******************************************************************************/
#ifndef HEADER_LIB_VR_VR_HPP
#define HEADER_LIB_VR_VR_HPP

namespace VR {

// Provide the path to a cubemap folder when initialising so the modern
// environment renderer can load the textures.
bool Initialize(const char* envCubemapFolder = nullptr);
void Shutdown();
void BeginFrame();
void EndFrame();

} // namespace VR

#endif // HEADER_LIB_VR_VR_HPP
