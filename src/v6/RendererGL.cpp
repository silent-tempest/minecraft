#include <iostream>
#include <GLFW/glfw3.h>
#include "RendererGL.h"

namespace v6 {

RendererGL::RendererGL ( char* name )
{
  const GLFWvidmode* mode = glfwGetVideoMode( glfwGetPrimaryMonitor() );
  create( mode->width, mode->height, name );
};

RendererGL::RendererGL ( int w, int h, char* name )
{
  create( w, h, name );  
}

void RendererGL::create ( int w, int h, char* name )
{
  if ( !glfwInit() ) {
    std::cerr << "Unable to initialize GLFW" << std::endl;
  }

  // int major = glVersion;
  // int minor = ( glVersion - float( major ) ) * 10;

  glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
  glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );

  window = glfwCreateWindow( w, h, name, nullptr, nullptr );

  if ( !window ) {
    std::cerr << "Unable to create a window" << std::endl;
  }

  glfwMakeContextCurrent( window );
}

void RendererGL::shaders ( Shader v, Shader f )
{
  program = new Program( v, f );
}

void RendererGL::rect ( int x, int y, int w, int h )
{
  static float vertices[ 8 ] = {
    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f,
    0.0f, 1.0f
  };
}

} // namespace v6
