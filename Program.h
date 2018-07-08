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

  inline ProgramAttribute get_attribute ( const char* name )
  {
    return attributes.get( name );
  }
 private:
  void load_attributes ();
  bool loaded_attributes = false;
  Map<ProgramAttribute> attributes;
  GLuint program;
};

#endif
