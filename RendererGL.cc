#include <iostream>
#include "include/GL/glew.h"    // glewInit(), GLEW_OK
#include "include/GLFW/glfw3.h"
#include "RendererGL.h"
#include "Program.h"
#include "Matrix.h"

RendererGL::RendererGL ( float version )
{
  matrix = new Matrix();

  if ( ! glfwInit() ) {
    std::cout << "Unable to initialize GLFW" << std::endl;
  }

  // int major = 4.3; // -> 4
  major = version;
  // int minor = ( 4.3 - 4.0 ) * 10; // -> 3
  minor = ( version - ( float ) major ) * 10;
}

RendererGL::RendererGL ()
{
  RendererGL( 2.0 );
}

RendererGL::~RendererGL ()
{

}

void RendererGL::create ( int w, int h, const char* name )
{
  glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, major );
  glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, minor );

  width = w;
  height = h;

  window = glfwCreateWindow( w, h, name, nullptr, nullptr );

  if ( ! window ) {
    std::cout << "Unable to create a window" << std::endl;
    return;
  }

  glfwMakeContextCurrent( window );

  if ( glewInit() != GLEW_OK ) {
    std::cout << "Unable to initialize GLEW" << std::endl;
  }

  glGenBuffers( 1, &buffer );
}

void RendererGL::create ( const char* name )
{
  const GLFWvidmode** mode = ( const GLFWvidmode** ) malloc( sizeof ( GLFWvidmode ) );

  *mode = glfwGetVideoMode( glfwGetPrimaryMonitor() );

  create( ( *mode )->width, ( *mode )->height, name );

  delete mode;
}

void RendererGL::add_shaders ( unsigned int index, Shader v, Shader f )
{
  if ( shaders.size() <= index ) {
    shaders.resize( index + 1, nullptr );
  }

  ( shaders )[ index ] = new Program( v, f );
}

void RendererGL::use_shaders ( unsigned int index )
{
  program = shaders.at( index );
}

void RendererGL::draw_vertices ( float* verts, int verts_count )
{
  if ( verts != nullptr ) {
    glBindBuffer( GL_ARRAY_BUFFER, buffer );
    glBufferData( GL_ARRAY_BUFFER, sizeof ( float ) * verts_count, verts, GL_STATIC_DRAW );
  }

  glUseProgram( program->program );

  glUniform2f( glGetUniformLocation( program->program, "res" ), width, height );
}

void RendererGL::rect ( int x, int y, int w, int h )
{
  static float verts[ 8 ] = {
    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f,
    0.0f, 1.0f
  };

  glPushMatrix();

  glTranslatef( x, y, 0.0f );

  glScalef( w, h, 1.0f );

  glBindBuffer( GL_ARRAY_BUFFER, buffer );

  glBufferData( GL_ARRAY_BUFFER, sizeof ( float ) * 8, verts, GL_STATIC_DRAW );

  draw_vertices( nullptr, 4 );

  glPopMatrix();
}
