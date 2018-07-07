#ifndef __RENDERERGL_H__
#define __RENDERERGL_H__

#include <vector>
#include "include/GLFW/glfw3.h"
#include "Transform.h"
#include "Program.h"
#include "Shader.h"

class RendererGL {
 public:
  RendererGL ();
  RendererGL ( float );
  ~RendererGL ();
  void create ( int, int, const char* );
  void create ( const char* );
  void add_shaders ( unsigned int, Shader, Shader );
  void use_shaders ( unsigned int );
  void draw_vertices ( float*, int );
  void rect ( int, int, int, int );
  GLuint buffer;
  Program* program;
  Transform* matrix;
  GLFWwindow* window;
  int width, height;
 private:
  int major, minor;
  std::vector<Program*> shaders;
};

#endif
