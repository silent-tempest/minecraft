#ifndef __MAP_PAIR_H__
#define __MAP_PAIR_H__

template <class T> class MapPair {
 public:
  MapPair ( std::string name, T value ) : name( name ), value( value ) {}

  inline std::string get_name ()
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
  std::string name;
  T value;
};

#endif
