#ifndef __MAP_H__
#define __MAP_H__

#include <stdexcept>
#include <string.h>
#include <vector>

#include "MapPair.h"

template <class T> class Map {
 public:
  ~Map ()
  {
    for ( int i = pairs.size() - 1; i >= 0; --i ) {
      delete pairs[ i ];
    }
  }

  T get ( const char* name )
  {
    MapPair<T>* pair = get_pair( name );

    if ( pair == nullptr ) {
      throw std::runtime_error( "Such the element wasn't found." );
    }

    return pair->get_value();
  }

  T set ( const char* name, T value )
  {
    MapPair<T>* pair = get_pair( name );

    if ( pair == nullptr ) {
      pairs.push_back( pair = new MapPair<T>( name, value ) );
    } else {
      pair->set_value( value );
    }

    return value;
  }
 private:
  MapPair<T>* get_pair ( const char* name )
  {
    for ( int i = pairs.size() - 1; i >= 0; --i ) {
      if ( strcmp( pairs[ i ]->get_name(), name ) == 0 ) {
        return pairs[ i ];
      }
    }

    return nullptr;
  }

  std::vector<MapPair<T>*> pairs;
};

#endif
