#include <algorithm>
#include "include/GLFW/glfw3.h"
#include "lib/timestamp.h"
#include "VirtualTicker.h"

void VirtualTicker::tick ()
{
  float last_time = timestamp(),
        skipped_time = 0;

  running = true;

  do {
    float now = timestamp(),
          dt = std::min( 1.0f, ( now - last_time ) * 0.001f );

    skipped_time += dt;
    total_time += dt;

    while ( skipped_time >= step ) {
      skipped_time -= step;
      update( step );
    }

    render( dt );
    last_time = now;
    glfwPollEvents();
  } while ( running );
}

void VirtualTicker::stop ()
{
  running = false;
}
