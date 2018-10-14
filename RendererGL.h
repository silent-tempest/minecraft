#ifndef __RENDERERGL_H__
#define __RENDERERGL_H__

#include <vector>
#include "include/GLFW/glfw3.h"
#include "include/GL/freeglut.h"
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
  void draw_vertices ( float*, int, GLint );
  void rect ( int, int, int, int );
  void line ( int, int, int, int );
  void arc ( int, int, float );
  void line_width ( float );
  GLuint buffer;
  Program* program;
  Transform* matrix;
  GLFWwindow* window;
  int width, height;
  float _line_width = 2;
  int r = 0;
  int g = 0;
  int b = 0;
 private:
  int major, minor;
  std::vector<Program*> shaders;
};

#endif
