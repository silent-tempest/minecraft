#include <iostream>
#include "../include/GL/glew.h"
#include "../include/GL/freeglut.h"
#include "../ProgramAttribute.h"
#include "../Program.h"
#include "../Shader.h"

Program::Program ( Shader v, Shader f )
{
  program = glCreateProgram();

  glAttachShader( program, v.shader );
  glAttachShader( program, f.shader );

  int ok;

  glLinkProgram( program );
  glGetProgramiv( program, GL_LINK_STATUS, &ok );

  if ( ! ok ) {
    char* log = new char[ 512 ];

    glGetProgramInfoLog( program, 512, nullptr, log );

    std::cout << "Unable to initialize the shader program: " << log << std::endl;

    delete[] log;
  }

  glValidateProgram( program );
  glGetProgramiv( program, GL_VALIDATE_STATUS, &ok );

  if ( ! ok ) {
    char* log = new char[ 512 ];

    glGetProgramInfoLog( program, 512, nullptr, log );

    std::cout << "Unable to validate the shader program: " << log << std::endl;

    delete[] log;
  }

  load_attributes();
  load_uniforms();
}

void Program::load_attributes ()
{
  if ( loaded_attributes ) {
    return;
  }

  GLint i;

  glGetProgramiv( program, GL_ACTIVE_ATTRIBUTES, &i );

  while ( --i >= 0 ) {
    GLsizei length;
    GLenum type;
    GLchar name[ 16 ];
    int size;

    glGetActiveAttrib( program, ( GLuint ) i, ( GLsizei ) 16, &length, &size, &type, name );

    GLint location = glGetAttribLocation( program, name );

    ProgramAttribute attr( name, type, size, location );

    attributes.set( std::string( name ), attr );
  }

  loaded_attributes = true;
}

void Program::load_uniforms ()
{
  if ( loaded_uniforms ) {
    return;
  }

  GLint i;

  glGetProgramiv( program, GL_ACTIVE_UNIFORMS, &i );

  while ( --i >= 0 ) {
    GLsizei length;
    GLenum type;
    GLchar name[ 16 ];
    int size;

    glGetActiveUniform( program, ( GLuint ) i, ( GLsizei ) 16, &length, &size, &type, name );

    GLint location = glGetUniformLocation( program, name );

    ProgramAttribute uniform( name, type, size, location );

    uniforms.set( std::string( name ), uniform );
  }

  loaded_uniforms = true;
}
