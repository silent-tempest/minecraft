#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include <vector>

class Transform {
 public:
  Transform ();
  ~Transform ();
  void push ();
  void pop ();
  void set_transform ( float, float, float, float, float, float );
  void translate ( float, float );
  void rotate ( float );
  void scale ( float, float );
  void transform ( float, float, float, float, float, float );
  float* matrix = new float[ 9 ];
 private:
  std::vector<float*> stack;
  int index = -1;
};

#endif
