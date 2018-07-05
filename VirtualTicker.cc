#include <algorithm>       // std::min()
#include "include/GLFW/glfw3.h"    // glfwPollEvents()
#include "VirtualTicker.h" // The header
#include "timestamp.h"     // timestamp()

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

void VirtualTicker::set_frame_rate ( float fps )
{
  step = 1.0f / fps;
}
