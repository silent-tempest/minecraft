#include "Ticker.h"

namespace v6 {

float timestamp ()
{
  timeb tb;
  ftime( &tb );
  return float( tb.millitm + ( tb.time & 0xfffff ) * 1000 );
}

Ticker::Ticker ()
{
  
}

void Ticker::tick ()
{
  float lastTime = timestamp(),
        skippedTime = 0,
        totalTime = 0;

  stopped = false;

  do {
    float now = timestamp(),
          dt = std::min( 1.0f, ( now - lastTime ) * 0.001f );

    skippedTime += dt;
    totalTime += dt;

    while ( skippedTime >= step ) {
      skippedTime -= step;
      update( step );
    }

    render( dt );

    lastTime = now;

    glfwPollEvents();

    if ( running ) {
      running = !glfwWindowShouldClose( window );
    }
  } while ( running );
}

void Ticker::stop ()
{
  running = false;
}

void Ticker::setFrameRate ( float fps )
{
  step = 1.0f / fps;
}

} // namespace v6
