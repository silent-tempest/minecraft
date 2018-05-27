#include <iostream>
#include <fstream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "Shader.h"

namespace v6 {

Shader::Shader ( GLuint type ) : type( type ) {}

void Shader::load ( char* path )
{
  std::ifstream file( path );

  if ( !file ) {
    std::cerr << "Unable to open shader" << std::endl;
  }

  std::string srcstr = std::string( ( std::istreambuf_iterator<char>( file ) ), std::istreambuf_iterator<char>() );

  const GLchar* src = srcstr.c_str();

  file.close();

  source( srcstr.c_str() );
}

void Shader::source ( const char* src )
{
  shader = glCreateShader( type );

  glShaderSource( shader, 1, &src, nullptr );
  glCompileShader( shader );

  int ok;

  glGetShaderiv( shader, GL_COMPILE_STATUS, &ok );

  if ( !ok ) {
    GLchar log[ 512 ];
    glGetShaderInfoLog( shader, 512, nullptr, log );
    std::cerr << "An error occurred compiling the shaders: " << log << std::endl;
  }
}

} // namespace v6
