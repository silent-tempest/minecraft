#include <sys/timeb.h>
#include "timestamp.h"

float timestamp ()
{
  timeb t;
  ftime( &t );
  return t.millitm + ( t.time & 0xfffff ) * 1000;
}
