#ifndef V6_RENDERERGL_H
#define V6_RENDERERGL_H

#include <GLFW/glfw3.h>
#include "Program.h"
#include "Shader.h"

namespace v6 {
  class RendererGL {
   public:
    RendererGL ( const char* );
    RendererGL ( int, int, const char* );
    void create ( int, int, const char* );
    void shaders ( Shader, Shader );
    void rect ( int, int, int, int );
    Program* program;
    GLFWwindow* window;
  };
}

#endif
