#ifndef V6_RENDERERGL_H
#define V6_RENDERERGL_H

// #include <GLFW/glfw3.h>
// #include "Shader.h"
// #include "Program.h"

namespace v6 {
  class RendererGL {
   public:
    RendererGL ( char* );
    RendererGL ( int, int, char* );
    void create ( int, int, char* );
    void shaders ( Shader, Shader );
    void rect ( int, int, int, int );
    Program* program;
    GLFWwindow* window;
  };
}

#endif
