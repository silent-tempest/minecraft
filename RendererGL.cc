#include <iostream>
#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h"
#include "RendererGL.h"
#include "Transform.h"
#include "Program.h"

RendererGL::RendererGL ( float version )
{
  matrix = new Transform();

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
  for ( int i = shaders.size() - 1; i >= 0; --i ) {
    if ( shaders[ i ] != nullptr ) {
      delete shaders[ i ];
    }
  }

  delete program;
  delete matrix;
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
  }

  glfwMakeContextCurrent( window );

  if ( glewInit() != GLEW_OK ) {
    std::cout << "Unable to initialize GLEW" << std::endl;
  }

  glGenBuffers( 1, &buffer );

  glViewport( 0, 0, w, h );

  glEnable( GL_DEPTH_TEST );
}

void RendererGL::create ( const char* name )
{
  const GLFWvidmode** mode = ( const GLFWvidmode** ) new GLFWvidmode;

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
    glBufferData( GL_ARRAY_BUFFER, sizeof ( float ) * verts_count, verts, GL_DYNAMIC_DRAW );
  }

  glUseProgram( program->get_program() );

  glUniform2f( glGetUniformLocation( program->get_program(), "res" ), width, height );

  glUniformMatrix3fv( glGetUniformLocation( program->get_program(), "transform" ), 1, false, matrix->matrix );

  glEnableVertexAttribArray( glGetAttribLocation( program->get_program(), "pos" ) );

  // glEnableVertexAttribArray( program->get_attribute( "pos" ).get_location() );

  glVertexAttribPointer( glGetAttribLocation( program->get_program(), "pos" ), 2, GL_FLOAT, false, 0, 0 );

  glUniform4f( glGetUniformLocation( program->get_program(), "color" ), 255.0f, 0.0f, 255.0f, 1.0f );

  glDrawArrays( GL_TRIANGLE_FAN, 0, verts_count );
}

void RendererGL::rect ( int x, int y, int w, int h )
{
  static float verts[ 8 ] = {
    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f,
    0.0f, 1.0f
  };

  matrix->push();

  matrix->translate( x, y );

  matrix->scale( w, h );

  glBindBuffer( GL_ARRAY_BUFFER, buffer );

  glBufferData( GL_ARRAY_BUFFER, sizeof ( float ) * 8, verts, GL_STATIC_DRAW );

  draw_vertices( nullptr, 4 );

  matrix->pop();
}
