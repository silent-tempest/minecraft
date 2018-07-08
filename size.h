#ifndef __SIZE_H__
#define __SIZE_H__

template <class T, int SIZE> inline int size ( const T ( &array )[ SIZE ] )
{
  return SIZE;
}

#endif
