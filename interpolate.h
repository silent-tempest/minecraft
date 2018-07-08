#ifndef __INTERPOLATE_H__
#define __INTERPOLATE_H__

template <class T> inline T lerp ( T x, T y, float value )
{
  return x + ( float ) ( y - x ) * value;
}

#endif
