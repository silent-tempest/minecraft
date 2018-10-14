#ifndef __MAT3_H__
#define __MAT3_H__

namespace mat3 {
  void set_identity ( float* );
  void copy ( float*, float* );
  void translate ( float*, float, float );
  void rotate ( float*, float );
  void scale ( float*, float, float );
  void transform ( float*, float, float, float, float, float, float );
  void set_transform ( float*, float, float, float, float, float, float );
}

#endif
