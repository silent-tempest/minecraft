#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
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
}

} // namespace v6
