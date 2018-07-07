#ifndef __SIZE_H__
#define __SIZE_H__

template <class TYPE, int LENGTH>

inline int size ( const TYPE ( &array )[ LENGTH ] )
{
  return LENGTH;
}

#endif
