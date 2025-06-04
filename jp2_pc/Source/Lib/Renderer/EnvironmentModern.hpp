/*
 * Modern Environment Renderer Stub
 * Provides a placeholder for a physically based rendering implementation.
 */

#ifndef HEADER_LIB_RENDERER_ENVIRONMENT_MODERN_HPP
#define HEADER_LIB_RENDERER_ENVIRONMENT_MODERN_HPP

namespace Renderer {

/**
 * Initialize the modern environment renderer.
 * 
 * @param cubemapFolder A folder containing six cubemap images:
 *        posx.png, negx.png, posy.png, negy.png, posz.png, and negz.png.
 *        If not applicable (e.g., stub implementation), may be nullptr.
 * @return True if initialization was successful.
 */
bool InitializeEnvironment(const char* cubemapFolder);

/**
 * Clean up any GL objects used for environment rendering.
 */
void ShutdownEnvironment();

/**
 * Render the environment cubemap.
 * 
 * @param view A 4x4 view matrix (column-major order).
 * @param proj A 4x4 projection matrix (column-major order).
 */
void RenderEnvironment(const float view[16], const float proj[16]);

} // namespace Renderer

#endif // HEADER_LIB_RENDERER_ENVIRONMENT_MODERN_HPP
