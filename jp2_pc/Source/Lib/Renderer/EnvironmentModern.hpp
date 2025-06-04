/*
 * Modern Environment Renderer Stub
 * Provides a placeholder for a physically based rendering implementation.
 */

#ifndef HEADER_LIB_RENDERER_ENVIRONMENT_MODERN_HPP
#define HEADER_LIB_RENDERER_ENVIRONMENT_MODERN_HPP

namespace Renderer {

/**
 * Initialise the modern environment renderer. A folder containing six
 * cubemap images is required. The images should be named
 * posx.png, negx.png, posy.png, negy.png, posz.png and negz.png.
 */
bool InitializeEnvironment(const char* cubemapFolder);

/** Clean up any GL objects used for environment rendering. */
void ShutdownEnvironment();

/**
 * Render the environment cubemap. The view and projection matrices must
 * be provided so that the skybox can be drawn correctly.
 */
void RenderEnvironment(const float view[16], const float proj[16]);

} // namespace Renderer

#endif // HEADER_LIB_RENDERER_ENVIRONMENT_MODERN_HPP
