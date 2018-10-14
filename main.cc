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

typedef struct {
  std::vector<Vector2D<float>> vertices;
  int r;
  int g;
  int b;
} Vertices;

namespace minecraft {
  class Ticker : public VirtualTicker {
   public:
    void update ( float );
    void render ( float );
  };

  std::vector<Vertices> shapes;
  RendererGL* renderer;
  Ticker* ticker;

  bool mouse_is_pressed = false;

  void on_mouse_press ( GLFWwindow* window, int button, int action, int modes )
  {
    if ( ( button == GLFW_MOUSE_BUTTON_LEFT || button == GLFW_MOUSE_BUTTON_RIGHT ) && ( mouse_is_pressed = ( action == GLFW_PRESS ) ) ) {
      Vertices vertices = {
        std::vector<Vector2D<float>>()
      };

      if ( button == GLFW_MOUSE_BUTTON_LEFT ) {
        vertices.r = 255;
        vertices.g = 0;
        vertices.b = 255;
      } else {
        vertices.r = 0;
        vertices.g = 255;
        vertices.b = 255;
      }

      shapes.push_back( vertices );
    }
  }

  void create ()
  {
    renderer = new RendererGL( 2.0 );
    renderer->create( 1080, 720, "Minecraft" );
    renderer->line_width( 100 );

    Shader v( GL_VERTEX_SHADER );
    Shader f( GL_FRAGMENT_SHADER );

    v.load( "shaders/basic.vert" );
    f.load( "shaders/basic.frag" );

    renderer->add_shaders( 0, v, f );
    renderer->use_shaders( 0 );

    glfwSetMouseButtonCallback( renderer->window, on_mouse_press );

    ticker = new Ticker();
  }

  void Ticker::update ( float elapsed_time )
  {
    if ( mouse_is_pressed ) {
      double x, y;
      glfwGetCursorPos( renderer->window, &x, &y );
      shapes.back().vertices.push_back( Vector2D<float>( ( float ) x, ( float ) y ) );
    }
  }

  void Ticker::render ( float elapsed_time )
  {
    glClearColor( 0.f, 0.f, 0.f, 1.f );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    for ( int i = shapes.size() - 1; i >= 0; --i ) {
      Vertices vertices = shapes[ i ];

      renderer->r = vertices.r;
      renderer->g = vertices.g;
      renderer->b = vertices.b;

      for ( int j = vertices.vertices.size() - 1; j > 0; --j ) {
        renderer->line( vertices.vertices[ j - 1 ].x, vertices.vertices[ j - 1 ].y, vertices.vertices[ j ].x, vertices.vertices[ j ].y );
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
