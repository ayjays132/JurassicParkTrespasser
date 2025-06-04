/*******************************************************************************
 * Oculus Quest VR stub interface.
 *******************************************************************************/
#ifndef HEADER_LIB_VR_VR_HPP
#define HEADER_LIB_VR_VR_HPP

namespace VR {

bool Initialize();
void Shutdown();
void BeginFrame();
void EndFrame();

} // namespace VR

#endif // HEADER_LIB_VR_VR_HPP
