#ifndef __SIZE_H__
#define __SIZE_H__

template <typename TYPE, int LENGTH>

inline int size ( const TYPE ( &array )[ LENGTH ] )
{
  return LENGTH;
}

#endif
