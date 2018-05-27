#ifndef V6_SHADER_H
#define V6_SHADER_H

#include <GL/freeglut.h>

namespace v6 {
  class Shader {
   public:
    Shader ( GLuint );
    void load ( char* );
    void source ( const char* );
    GLuint type;
    GLuint shader;
  };
}

#endif
