#ifndef V6_PROGRAM_H
#define V6_PROGRAM_H

#include <vector>
#include "Shader.h"

namespace v6 {
  struct Attribute {
    Attribute ( char* _name, int _type, int _size, int _location ) : name( _name ), type( _type ), size( _size ), location( _location ) {}
    char* name;
    int type;
    int size;
    int location;
  };

  class Program {
   public:
    Program ( Shader, Shader );
    std::vector<Attribute> attributes;
    std::vector<Attribute> uniforms;
   private:
    void loadAttrs ();
    void loadUniforms ();
    GLuint program;
  };
}

#endif
