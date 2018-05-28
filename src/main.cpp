/**
 * Compile: g++ -o main.deb src/main.cpp -I src/*.cpp -I src/v6/*.cpp -lGL -lGLEW -lglfw
 */

// #include <iostream>      // std::cout, std::endl, std::cerr
// #include <fstream>       // std::ifstream
// #include <sstream>       // std::stringstream
// #include <streambuf>     // std::istreambuf_iterator
// #include <sys/timeb.h>   // ftime (to implement timestamp())
// #include <algorithm>     // std::min
// #include <GL/glew.h>     // GLEW
// #include <GLFW/glfw3.h>  // Use GLFW to create a window
// #include <GL/freeglut.h> // OpenGL
// #include "v6/v6.h"       // v6.js implementation
// #include "v6/Ticker.h"
// #include "v6/Shader.h"
// #include "v6/Program.h"
// #include "v6/RendererGL.h"

#include "v6/v6.h"
#include "v6/Ticker.h"
#include "v6/Shader.h"
#include "v6/Program.h"
#include "v6/RendererGL.h"

namespace minecraft {
  class Ticker : public v6::Ticker {
   public:
    void update ( float );
    void render ( float );
  };

  float r = 0.0f,
        g = 0.0f,
        b = 0.0f;

  v6::RendererGL* renderer;
  Ticker* ticker;

  void init ()
  {
    renderer = new v6::RendererGL( 640, 480, "Minecraft" );

    v6::Shader v( GL_VERTEX_SHADER ),
               f( GL_FRAGMENT_SHADER );

    v.load( "shaders/v.glsl" );
    f.load( "shaders/f.glsl" );

    renderer->shaders( v, f );

    ticker = new Ticker();

    ticker->tick();
  }

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
    glfwSwapBuffers( renderer->window );

    if ( glfwWindowShouldClose( renderer->window ) ) {
      stop();
    }
  }
}

int main ( int argc, char** argv )
{
  minecraft::init();
  return 0;
}
