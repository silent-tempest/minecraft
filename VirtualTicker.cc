#include <algorithm>
#include "include/GLFW/glfw3.h"
#include "VirtualTicker.h"
#include "timestamp.h"

void VirtualTicker::tick ()
{
  float last_require_time = timestamp(),
        skipped_time      = 0;

  running = true;

  do {
    float now          = timestamp(),
          elapsed_time = std::min( 1.0f, ( now - last_require_time ) * 0.001f );

    skipped_time += elapsed_time;

    total_time += elapsed_time;

    while ( skipped_time >= step && running ) {
      skipped_time -= step;
      update( step );
    }

    render( elapsed_time );

    last_require_time = now;

    glfwPollEvents();
  } while ( running );
}

void VirtualTicker::stop ()
{
  running = false;
}
