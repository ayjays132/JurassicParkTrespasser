#include "VR.hpp"
#ifdef ENABLE_OCULUS_QUEST_SUPPORT
#include "Lib/Renderer/EnvironmentModern.hpp"
#include <GLES3/gl3.h>
#include <cmath>
#endif
#include <cstdio>
#ifdef USE_SDL_CONTROLLER
#include <SDL2/SDL.h>
#endif

namespace VR {

bool Initialize(const char *envCubemapFolder) {
  // Placeholder for Oculus Quest initialization
  std::printf("VR Initialize stub\n");

#ifdef ENABLE_OCULUS_QUEST_SUPPORT
  bool ok = false;
  if (envCubemapFolder) {
    ok = Renderer::InitializeEnvironment(envCubemapFolder);
  } else {
    ok = Renderer::InitializeEnvironment("assets/env");
  }
  if (!ok)
    std::fprintf(stderr, "Failed to initialise environment renderer\n");
  Renderer::SetEnvironmentIntensity(1.0f);
#endif

  return true;
}

void Shutdown() {
  // Placeholder cleanup
  std::printf("VR Shutdown stub\n");

#ifdef ENABLE_OCULUS_QUEST_SUPPORT
  Renderer::ShutdownEnvironment();
#endif
}

void BeginFrame() {
  // Placeholder per-frame begin
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
  // Placeholder per-frame end
#ifdef ENABLE_OCULUS_QUEST_SUPPORT
  float identity[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
  Renderer::RenderEnvironment(identity, identity);
#endif
}

SInput GetControllerInput() {
  SInput input{};
#ifdef ENABLE_OCULUS_QUEST_SUPPORT
  // Integrate actual VR controller input here when available
#endif
#ifdef USE_SDL_CONTROLLER
  static bool init = false;
  if (!init) {
    if (SDL_WasInit(SDL_INIT_GAMECONTROLLER) == 0)
      SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER);
    init = true;
  }
  for (int i = 0; i < SDL_NumJoysticks(); ++i) {
    if (!SDL_IsGameController(i))
      continue;
    SDL_GameController *ctrl = SDL_GameControllerOpen(i);
    if (!ctrl)
      continue;
    const Sint16 lx = SDL_GameControllerGetAxis(ctrl, SDL_CONTROLLER_AXIS_LEFTX);
    const Sint16 ly = SDL_GameControllerGetAxis(ctrl, SDL_CONTROLLER_AXIS_LEFTY);
    const Sint16 rx = SDL_GameControllerGetAxis(ctrl, SDL_CONTROLLER_AXIS_RIGHTX);
    const Sint16 ry = SDL_GameControllerGetAxis(ctrl, SDL_CONTROLLER_AXIS_RIGHTY);
    input.v2Move = CVector2<>(lx / 32767.0f, -ly / 32767.0f);
    input.v2Rotate = CVector2<>(rx / 32767.0f, -ry / 32767.0f);
    if (SDL_GameControllerGetButton(ctrl, SDL_CONTROLLER_BUTTON_A))
      input.u4ButtonState |= uCMD_USE;
    SDL_GameControllerClose(ctrl);
    break;
  }
#endif
  return input;
}

} // namespace VR
