#include <iostream>
#include <vector>

#include "include/GLFW/glfw3.h"
#include "include/GL/freeglut.h"

#include "ProgramAttribute.h"
#include "VirtualTicker.h"
#include "RendererGL.h"
#include "Vector2D.h"
#include "Shader.h"

using std::cout;
using std::endl;

namespace minecraft {
  class Ticker : public VirtualTicker {
   public:
    void update ( float );
    void render ( float );
  };

  std::vector<std::vector<Vector2D<float>>> shapes;

  RendererGL* renderer;

  Ticker* ticker;

  bool mouse_is_pressed = false;

  void on_mouse_press ( GLFWwindow* window, int button, int action, int modes )
  {
    if ( button == GLFW_MOUSE_BUTTON_LEFT ) {
      if ( ( mouse_is_pressed = action == GLFW_PRESS ) ) {
        shapes.push_back( std::vector<Vector2D<float>>() );
      }
    }
  }

  void create ()
  {
    renderer = new RendererGL( 2.0 );

    renderer->create( "Minecraft" );

    Shader v( GL_VERTEX_SHADER ),
           f( GL_FRAGMENT_SHADER );

    v.load( "shaders/basic.vert" );
    f.load( "shaders/basic.frag" );

    renderer->add_shaders( 0, v, f );
    renderer->use_shaders( 0 );

    glfwSetMouseButtonCallback( renderer->window, on_mouse_press );

    ticker = new Ticker();
  }

  float r = 0.0f,
        g = 0.0f,
        b = 0.0f;

  void Ticker::update ( float elapsed_time )
  {
    r += 0.75f * elapsed_time;
    g += 0.25f * elapsed_time;
    b += 0.75f * elapsed_time;

    if ( mouse_is_pressed ) {
      double x, y;

      glfwGetCursorPos( renderer->window, &x, &y );

      shapes.back().push_back( Vector2D<float>( ( float ) x, ( float ) y ) );
    }
  }

  void Ticker::render ( float elapsed_time )
  {
    glClearColor( r, g, b, 1.0f );

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    for ( int i = shapes.size() - 1; i >= 0; --i ) {
      std::vector<Vector2D<float>> points = shapes[ i ];

      for ( int j = points.size() - 1; j > 0; --j ) {
        renderer->line( points[ j - 1 ].x, points[ j - 1 ].y + 60, points[ j ].x, points[ j ].y + 60 );
      }
    }

    glfwSwapBuffers( renderer->window );

    if ( glfwWindowShouldClose( renderer->window ) ) {
      stop();
    }
  }
}


int main ( int argc, const char* argv[] )
{
  minecraft::create();

  minecraft::ticker->tick();

  return 0;
}
