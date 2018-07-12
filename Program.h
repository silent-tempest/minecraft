#ifndef __PROGRAM_H__
#define __PROGRAM_H__

#include "include/GL/freeglut.h"
#include "ProgramAttribute.h"
#include "Shader.h"
#include "Map.h"

class Program {
 public:
  Program ( Shader, Shader );

  inline GLuint get_program ()
  {
    return program;
  }

  inline ProgramAttribute get_attribute ( std::string name )
  {
    return attributes.get( name );
  }

  inline ProgramAttribute get_uniform ( std::string name )
  {
    return uniforms.get( name );
  }
 private:
  void load_attributes ();
  void load_uniforms ();
  bool loaded_attributes = false;
  bool loaded_uniforms = false;
  Map<ProgramAttribute> attributes;
  Map<ProgramAttribute> uniforms;
  GLuint program;
};

#endif
