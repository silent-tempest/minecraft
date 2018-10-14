#include <cmath>
#include "mat3.h"

namespace mat3 {

void set_identity ( float* m1 )
{
  m1[ 0 ] = m1[ 4 ] = m1[ 8 ] = 1;
  m1[ 1 ] = m1[ 2 ] = m1[ 3 ] = m1[ 5 ] = m1[ 6 ] = m1[ 7 ] = 0;
}

void copy ( float* m1, float* m2 )
{
  m1[ 0 ] = m2[ 0 ];
  m1[ 1 ] = m2[ 1 ];
  m1[ 2 ] = m2[ 2 ];
  m1[ 3 ] = m2[ 3 ];
  m1[ 4 ] = m2[ 4 ];
  m1[ 5 ] = m2[ 5 ];
  m1[ 6 ] = m2[ 6 ];
  m1[ 7 ] = m2[ 7 ];
  m1[ 8 ] = m2[ 8 ];
}

void translate ( float* m1, float x, float y )
{
  m1[ 6 ] = x * m1[ 0 ] + y * m1[ 3 ] + m1[ 6 ];
  m1[ 7 ] = x * m1[ 1 ] + y * m1[ 4 ] + m1[ 7 ];
  m1[ 8 ] = x * m1[ 2 ] + y * m1[ 5 ] + m1[ 8 ];
}

void rotate ( float* m1, float angle )
{
  float m10 = m1[ 0 ],
        m11 = m1[ 1 ],
        m12 = m1[ 2 ],
        m13 = m1[ 3 ],
        m14 = m1[ 4 ],
        m15 = m1[ 5 ];

  float x = std::cos( angle ),
        y = std::sin( angle );

  m1[ 0 ] = x * m10 + y * m13;
  m1[ 1 ] = x * m11 + y * m14;
  m1[ 2 ] = x * m12 + y * m15;
  m1[ 3 ] = x * m13 - y * m10;
  m1[ 4 ] = x * m14 - y * m11;
  m1[ 5 ] = x * m15 - y * m12;
}

void scale ( float* m1, float x, float y )
{
  m1[ 0 ] *= x;
  m1[ 1 ] *= x;
  m1[ 2 ] *= x;
  m1[ 3 ] *= y;
  m1[ 4 ] *= y;
  m1[ 5 ] *= y;
}

void transform ( float* m1, float m11, float m12, float m21, float m22, float dx, float dy )
{
  m1[ 0 ] *= m11;
  m1[ 1 ] *= m21;
  m1[ 2 ] *= dx;
  m1[ 3 ] *= m12;
  m1[ 4 ] *= m22;
  m1[ 5 ] *= dy;
  m1[ 6 ] = 0;
  m1[ 7 ] = 0;
}

void set_transform ( float* m1, float m11, float m12, float m21, float m22, float dx, float dy )
{
  m1[ 0 ] = m11; // x scale
  m1[ 1 ] = m12; // x skew
  m1[ 3 ] = m21; // y skew
  m1[ 4 ] = m22; // y scale
  m1[ 6 ] = dx;  // x translate
  m1[ 7 ] = dy;  // y translate
}

} // namespace mat3
