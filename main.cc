#include <vector>
#include <iostream>
#include "include/GLFW/glfw3.h"
#include "include/GL/freeglut.h"
#include "Matrix.h"
#include "Shader.h"
#include "RendererGL.h"
#include "VirtualTicker.h"

using std::cout;
using std::endl;

namespace minecraft {
  class Ticker : public VirtualTicker {
   public:
    void update ( float );
    void render ( float );
  };

  RendererGL* renderer;

  Ticker* ticker;

  void create ()
  {
    renderer = new RendererGL( 4.3 );

    renderer->create( "Minecraft" );

    Shader v( GL_VERTEX_SHADER ),
           f( GL_FRAGMENT_SHADER );

    v.load( "shaders/basic.vert" );
    f.load( "shaders/basic.frag" );

    renderer->add_shaders( 0, v, f );
    renderer->use_shaders( 0 );

    ticker = new Ticker();
  }

  float r = 0.0f,
        g = 0.0f,
        b = 0.0f;

  void Ticker::update ( float dt )
  {
    r += 0.01f;
    g += 0.01f;
    b += 0.01f;
  }

  void Ticker::render ( float dt )
  {
    glClearColor( r, g, b, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // renderer->rect( 100, 100, 100, 100 );

    glfwSwapBuffers( renderer->window );

    if ( glfwWindowShouldClose( renderer->window ) ) {
      stop();
    }
  }
}

class TestClass {
 public:
  TestClass ();
  ~TestClass ();
  const char* test = "TEST";
};

TestClass::TestClass ()
{
  cout << "new <TestClass>" << endl;
}

TestClass::~TestClass ()
{
  cout << "delete <TestClass>" << endl;
}

int main ( int argc, char const* argv[] )
{
  minecraft::create();

  minecraft::ticker->tick();

  return 0;
}
