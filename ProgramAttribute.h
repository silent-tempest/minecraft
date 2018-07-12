#ifndef __PROGRAM_ATTRIBUTE_H__
#define __PROGRAM_ATTRIBUTE_H__

#include "include/GL/freeglut.h"

class ProgramAttribute {
 public:
  inline ProgramAttribute ( std::string name, GLenum type, int size, int location )
    : name( name ), type( type ), size( size ), location( location )
  {}
  
  inline std::string get_name ()
  {
    return name;
  }

  inline GLenum get_type ()
  {
    return type;
  }

  inline int get_size ()
  {
    return size;
  }

  inline int get_location ()
  {
    return location;
  }
 private:
  std::string name;
  GLenum type;
  int size, location;
};

#endif
