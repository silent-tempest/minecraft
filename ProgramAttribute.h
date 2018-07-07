#ifndef __PROGRAM_ATTRIBUTE_H__
#define __PROGRAM_ATTRIBUTE_H__

#include "include/GL/freeglut.h"

class ProgramAttribute {
 public:
  ProgramAttribute ( const char*, GLenum, int, int );
  
  inline const char* get_name ()
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
  const char* name;
  GLenum type;
  int size, location;
};

#endif
