#ifndef __SHADER_H__
#define __SHADER_H__

#include "include/GL/freeglut.h"

class Shader {
 public:
  Shader ( GLuint );
  void load ( const char* );
  void source ( const char* );
  GLuint type;
  GLuint shader;
};

#endif
