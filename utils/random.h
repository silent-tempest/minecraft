#ifndef __RANDOM_H__
#define __RANDOM_H__

#include <cstdlib>
#include <ctime>

bool __random_is_not_initialized__ = true;

inline float random ( float lower, float upper )
{
  if ( __random_is_not_initialized__ ) {
    srand( time( nullptr ) );
    __random_is_not_initialized__ = false;
  }

  return lower + ( float ) rand() / ( float ) RAND_MAX * ( upper - lower );
}

#endif
