#ifndef __PROGRAM_H__
#define __PROGRAM_H__

#include "include/GL/freeglut.h"
#include "Shader.h"

class Program {
 public:
  Program ( Shader, Shader );
  void load_uniforms ();
  GLuint program;
};

#endif
