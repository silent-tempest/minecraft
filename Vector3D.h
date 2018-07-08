#ifndef __VECTOR3D__
#define __VECTOR3D__

#include <sstream>

template <class T> class Vector3D {
 public:
  inline Vector3D ( T x, T y, T z ) : x( x ), y( y ), z( z ) {};

  template <template <class> class OtherVector> inline Vector3D ( OtherVector<T> vector )
  {
    Vector3D( vector.x, vector.y, vector.z );
  }

  inline void set ( T _x, T _y, T _z )
  {
    x = _x;
    y = _y;
    z = _z;
  }

  template <template <class> class OtherVector> inline void set_vector ( OtherVector<T> vector )
  {
    set( vector.x, vector.y, vector.z );
  }

  inline void add ( T _x, T _y, T _z )
  {
    x += _x;
    y += _y;
    z += _z;
  }

  template <template <class> class OtherVector> inline void add_vector ( OtherVector<T> vector )
  {
    add( vector.x, vector.y, vector.z );
  }

  inline void sub ( T _x, T _y, T _z )
  {
    x -= _x;
    y -= _y;
    z -= _z;
  }

  template <template <class> class OtherVector> inline void sub_vector ( OtherVector<T> vector )
  {
    sub( vector.x, vector.y, vector.z );
  }

  inline std::ostringstream to_ostringstream ()
  {
    std::ostringstream stream;

    stream << "vec2(" << x << ", " << y << ", " << z << ")";

    return stream;
  }

  T x, y, z;
};

#endif
