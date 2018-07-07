#ifndef __MAP_PAIR_H__
#define __MAP_PAIR_H__

template <class T> class MapPair {
 public:
  MapPair ( const char* name, T value ) : name( name ), value( value ) {}

  inline const char* get_name ()
  {
    return name;
  }

  inline T get_value ()
  {
    return value;
  }

  inline T set_value ( T value )
  {
    return ( this->value = value );
  }
 private:
  const char* name;
  T value;
};

#endif
