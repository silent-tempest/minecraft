#include <iostream>
#include "include/GL/glew.h"
#include "include/GL/freeglut.h"
#include "Program.h"

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

    return;
  }

  glValidateProgram( program );
  glGetProgramiv( program, GL_VALIDATE_STATUS, &ok );

  if ( ! ok ) {
    char* log = new char[ 512 ];

    glGetProgramInfoLog( program, 512, nullptr, log );

    std::cout << "Unable to validate the shader program: " << log << std::endl;

    delete[] log;
  }
}

void Program::load_uniforms ()
{
  
}
