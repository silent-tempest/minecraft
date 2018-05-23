#include "Program.h"

namespace v6 {

Program::Program ( Shader v, Shader f )
{
  program = glCreateProgram();

  glAttachShader( program, v.shader );
  glAttachShader( program, f.shader );

  int ok;

  glLinkProgram( program );
  glGetProgramiv( program, GL_LINK_STATUS, &ok );

  if ( !ok ) {
    GLchar log[ 512 ];
    glGetProgramInfoLog( program, 512, nullptr, log );
    std::cerr << "Unable to initialize the shader program: " << log << std::endl;
  }

  glValidateProgram( program );
  glGetProgramiv( program, GL_VALIDATE_STATUS, &ok );

  if ( !ok ) {
    GLchar log[ 512 ];
    glGetProgramInfoLog( program, 512, nullptr, log );
    std::cerr << "Unable to validate the shader program" << log << std::endl;
  }

  loadAttrs();
  loadUniforms();
}

void Program::loadAttrs ()
{
  short i = glGetProgramiv( program, GL_ACTIVE_ATTRIBUTES ) - 1;

  for ( ; i >= 0; --i ) {
    GLuint info = glGetActiveAttrib( program, i );
    Attribute attr( info.name, info.type, info.size, glGetAttributeLocation( program, info.name ) );
    attributes.push_back( attr );
  }
}

void Program::loadUniforms ()
{
  short i = glGetProgramiv( program, GL_ACTIVE_UNIFORMS ) - 1;

  for ( ; i >= 0; --i ) {
    GLuint info = glGetActiveUniform( program, i );
    Attribute uniform( info.name, info.type, info.size, glGetUniformLocation( program, info.name ) );
    attributes.push_back( attr );
  }
}

} // namespace v6
