#pragma once

#ifdef ENABLE_OCULUS_QUEST_SUPPORT

#include "EnvironmentModern.hpp"
#include "../Transform/Vector.hpp"
#include <cstdio>
#include <string>
#include <vector>

#ifdef __ANDROID__
#include <GLES3/gl3.h>
#include <android/log.h>
#endif

#include "../../../ThirdParty/stb/stb_image.h"

namespace Renderer {

namespace {
GLuint gProgram = 0;
GLuint gVAO = 0;
GLuint gVBO = 0;
GLuint gCubemap = 0;
float gIntensity = 1.0f;
float gRotation[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};

const char *vShader = R"(
#version 300 es
layout(location=0) in vec3 aPos;
uniform mat4 uView;
uniform mat4 uProj;
uniform mat4 uRot;
out vec3 TexCoord;
void main() {
    TexCoord = mat3(uRot) * aPos;
    vec4 pos = uProj * uView * uRot * vec4(aPos, 1.0);
    gl_Position = pos.xyww;
}
)";

const char *fShader = R"(
#version 300 es
in vec3 TexCoord;
out vec4 FragColor;
uniform samplerCube uSkybox;
uniform float uIntensity;
void main() {
    FragColor = texture(uSkybox, TexCoord) * uIntensity;
}
)";

GLuint Compile(GLenum type, const char *src) {
  GLuint s = glCreateShader(type);
  glShaderSource(s, 1, &src, nullptr);
  glCompileShader(s);
  return s;
}

bool LoadCubemap(const char *folder) {
  const char *names[6] = {"posx.png", "negx.png", "posy.png",
                          "negy.png", "posz.png", "negz.png"};
  glGenTextures(1, &gCubemap);
  glBindTexture(GL_TEXTURE_CUBE_MAP, gCubemap);

  for (int i = 0; i < 6; i++) {
    std::string path = std::string(folder) + "/" + names[i];
    int w, h, comp;
    unsigned char *data = stbi_load(path.c_str(), &w, &h, &comp, 4);
    if (!data) {
#ifdef __ANDROID__
      __android_log_print(ANDROID_LOG_ERROR, "Trespasser", "Failed to load %s",
                          path.c_str());
#else
      std::fprintf(stderr, "Failed to load %s\n", path.c_str());
#endif
      return false;
    }
    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGBA, w, h, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, data);
    stbi_image_free(data);
  }

  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

  return true;
}
} // namespace

bool InitializeEnvironment(const char *folder) {
#ifdef __ANDROID__
  __android_log_print(ANDROID_LOG_INFO, "Trespasser",
                      "Modern environment renderer init");
#else
  std::printf("Modern environment renderer init\n");
#endif

  GLuint vs = Compile(GL_VERTEX_SHADER, vShader);
  GLuint fs = Compile(GL_FRAGMENT_SHADER, fShader);

  gProgram = glCreateProgram();
  glAttachShader(gProgram, vs);
  glAttachShader(gProgram, fs);
  glLinkProgram(gProgram);

  glDeleteShader(vs);
  glDeleteShader(fs);

  float vertices[] = {
      -1, 1,  -1, -1, -1, -1, 1,  -1, -1, 1,  -1, -1, 1,  1,  -1, -1, 1,  -1,
      -1, -1, 1,  -1, -1, -1, -1, 1,  -1, -1, 1,  -1, -1, 1,  1,  -1, -1, 1,
      1,  -1, -1, 1,  -1, 1,  1,  1,  1,  1,  1,  1,  1,  1,  -1, 1,  -1, -1,
      -1, -1, 1,  -1, 1,  1,  1,  1,  1,  1,  1,  1,  1,  -1, 1,  -1, -1, 1,
      -1, 1,  -1, 1,  1,  -1, 1,  1,  1,  1,  1,  1,  -1, 1,  1,  -1, 1,  -1,
      -1, -1, -1, -1, -1, 1,  1,  -1, -1, 1,  -1, -1, -1, -1, 1,  1,  -1, 1};

  glGenVertexArrays(1, &gVAO);
  glGenBuffers(1, &gVBO);
  glBindVertexArray(gVAO);
  glBindBuffer(GL_ARRAY_BUFFER, gVBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

  return LoadCubemap(folder);
}

void ShutdownEnvironment() {
  glDeleteBuffers(1, &gVBO);
  glDeleteVertexArrays(1, &gVAO);
  glDeleteProgram(gProgram);
  glDeleteTextures(1, &gCubemap);
  gVAO = gVBO = gProgram = gCubemap = 0;

#ifdef __ANDROID__
  __android_log_print(ANDROID_LOG_INFO, "Trespasser",
                      "Modern environment renderer shutdown");
#else
  std::printf("Modern environment renderer shutdown\n");
#endif
}

void RenderEnvironment(const float view[16], const float proj[16]) {
  glDepthFunc(GL_LEQUAL);
  glUseProgram(gProgram);

  glUniformMatrix4fv(glGetUniformLocation(gProgram, "uView"), 1, GL_FALSE,
                     view);
  glUniformMatrix4fv(glGetUniformLocation(gProgram, "uProj"), 1, GL_FALSE,
                     proj);
  glUniformMatrix4fv(glGetUniformLocation(gProgram, "uRot"), 1, GL_FALSE,
                     gRotation);
  glUniform1f(glGetUniformLocation(gProgram, "uIntensity"), gIntensity);

  glBindVertexArray(gVAO);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_CUBE_MAP, gCubemap);

  glDrawArrays(GL_TRIANGLES, 0, 36);

  glDepthFunc(GL_LESS);
}

void SetEnvironmentIntensity(float intensity) { gIntensity = intensity; }

void SetEnvironmentRotation(const float rotation[16]) {
  for (int i = 0; i < 16; ++i) {
    gRotation[i] = rotation[i];
  }
}

} // namespace Renderer

#endif // ENABLE_OCULUS_QUEST_SUPPORT
