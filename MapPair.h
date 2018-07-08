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

  inline void set_value ( T new_value )
  {
    value = new_value;
  }
 private:
  const char* name;
  T value;
};

#endif
