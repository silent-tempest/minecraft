#ifndef __TIMESTAMP_H__
#define __TIMESTAMP_H__

#include <sys/timeb.h>

inline float timestamp ()
{
  timeb t;
  ftime( &t );
  return t.millitm + ( t.time & 0xfffff ) * 1000;
}

#endif
