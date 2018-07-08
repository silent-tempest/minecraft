#ifndef __VECTOR2D__
#define __VECTOR2D__

#include <sstream>

template <class T> class Vector2D {
 public:
  inline Vector2D () : x( ( T ) 0 ), y( ( T ) 0 ) {};

  inline Vector2D ( T x, T y ) : x( x ), y( y ) {};

  template <template <class> class OtherVector> inline Vector2D ( OtherVector<T> vector )
  {
    Vector2D( vector.x, vector.y );
  }

  inline void set ( T _x, T _y )
  {
    x = _x;
    y = _y;
  }

  template <template <class> class OtherVector> inline void set_vector ( OtherVector<T> vector )
  {
    set( vector.x, vector.y );
  }

  inline void add ( T _x, T _y )
  {
    x += _x;
    y += _y;
  }

  template <template <class> class OtherVector> inline void add_vector ( OtherVector<T> vector )
  {
    add( vector.x, vector.y );
  }

  inline void sub ( T _x, T _y )
  {
    x -= _x;
    y -= _y;
  }

  template <template <class> class OtherVector> inline void sub_vector ( OtherVector<T> vector )
  {
    sub( vector.x, vector.y );
  }

  inline std::ostringstream to_ostringstream ()
  {
    std::ostringstream stream;

    stream << "vec2(" << x << ", " << y << ")";

    return stream;
  }

  T x, y;
};

#endif
