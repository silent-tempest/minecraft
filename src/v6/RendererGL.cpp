#include "RendererGL.h"

namespace v6 {

RendererGL::RendererGL ( char* name )
{
  GLFWvidmode desktop;
  glfwGetDesktopMode( &desktop );
  create( desktop.Width, desktop.Height, name );
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
  program = Program( v, f );
}

void RendererGL::rect ( int x, int y, int w, int h )
{
  static float vertices[] = {
    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f,
    0.0f, 1.0f
  };
}

} // namespace v6
