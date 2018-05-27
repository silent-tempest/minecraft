#ifndef V6_PROGRAM_H
#define V6_PROGRAM_H

#include <GL/freeglut.h>
#include "Shader.h"

namespace v6 {
  class Program {
   public:
    Program ( Shader, Shader );
   private:
    GLuint program;
  };
}

#endif
