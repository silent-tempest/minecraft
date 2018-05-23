#ifndef V6_TICKER_H
#define V6_TICKER_H

namespace v6 {
  class Ticker {
   public:
    Ticker ();
    void tick ();
    void stop ();
    void setFrameRate ( float );
    virtual void update ( float );
    virtual void render ( float );
   private:
    float step = 1.0f / 60.0f;
    bool running = false;
  };
}

#endif
