#include <iostream>
#include <fstream>   // std::ifstream
#include <streambuf> // std::istreambuf_iterator
#include "../include/GL/glew.h"
#include "../Shader.h"

Shader::Shader ( GLuint type ) : type( type ) {}

void Shader::load ( const char* path )
{
  std::ifstream file( path );

  if ( ! file ) {
    std::cout << "Unable to open shader" << std::endl;
    return;
  }

  std::string srcstr = std::string( std::istreambuf_iterator<char>( file ), std::istreambuf_iterator<char>() );

  const char* src = srcstr.c_str();

  file.close();

  source( src );
}

void Shader::source ( const char* src )
{
  shader = glCreateShader( type );

  glShaderSource( shader, 1, &src, nullptr );
  glCompileShader( shader );

  int ok;

  glGetShaderiv( shader, GL_COMPILE_STATUS, &ok );

  if ( ! ok ) {
    char* log = new char[ 512 ];

    glGetShaderInfoLog( shader, 512, nullptr, log );

    std::cout << "An error occurred compiling the shaders: " << log << std::endl;

    delete[] log;
  }
}
