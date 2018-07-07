#ifndef __VIRTUAL_TICKER_H__
#define __VIRTUAL_TICKER_H__

class VirtualTicker {
 public:
  void tick ();
  void stop ();
  virtual void update ( float ) = 0;
  virtual void render ( float ) = 0;
  float total_time = 0;
 private:
  float step = 1.0f / 60.0f;
  bool running = false;
};

#endif
