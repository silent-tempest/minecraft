/**
 * Compile: g++ -o main.deb src/main.cpp -lGLEW -lGL -lX11 -lpthread -lXrandr -lGLU -lglfw
 */

// std::cout, std::cerr, std::endl
#include <iostream>
// std::ifstream
#include <fstream>
// std::stringstream
#include <sstream>
// std::istreambuf_iterator
#include <streambuf>
// ftime
#include <sys/timeb.h>
// std::min
#include <algorithm>
// GLEW
#include <GL/glew.h>
// Use GLFW to create a window
#include <GLFW/glfw3.h>
// OpenGL
#include <GL/freeglut.h>

void error ( int, const char* );
void tick ();
void update ( float );
void render ();
float timestamp ();
GLuint createShader ( char*, int );
GLuint createProgram ( GLuint, GLuint );

float r = 0,
      g = 0,
      b = 0;

bool stopped = true;

GLFWwindow* window;
GLuint program;

int main ( int argc, char** argv )
{

  if ( !glfwInit() ) {
    throw "Can't initialize GLFW";
  }

  glfwSetErrorCallback( error );

  glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 2 );
  glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 0 );

  window = glfwCreateWindow( 640, 480, "Minecraft", NULL, NULL );

  if ( !window ) {
    throw "Can't create a window";
  }

  glfwMakeContextCurrent( window );

  program = createProgram(
    createShader( "shaders/vert.glsl", GL_VERTEX_SHADER ),
    createShader( "shaders/frag.glsl", GL_FRAGMENT_SHADER ) );

  glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
  glEnable( GL_BLEND );

  tick();

  return 0;

}

void error ( int error, const char* description )
{
  std::cerr << "Error: " << description << std::endl;
}

void tick ()
{
  float lastTime = timestamp();

  float skippedTime = 0,
        totalTime = 0,
        step = 1.0f / 60.0f;

  bool needRender;

  stopped = false;

  do {
    float now = timestamp(),
          dt = std::min( 1.0f, ( now - lastTime ) / 1000 );

    skippedTime += dt;
    totalTime += dt;
    needRender = skippedTime > step;

    while ( skippedTime >= step ) {
      skippedTime -= step;
      update( step );
    }

    render();

    lastTime = now;

    glfwPollEvents();

    if ( !stopped ) {
      stopped = glfwWindowShouldClose( window );
    }

  } while ( !stopped );
}

void update ( float dt )
{
  r += 0.01f;
  g += 0.01f;
  b += 0.01f;
}

void render ()
{
  glClearColor( r, g, b, 1.0f );
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glfwSwapBuffers( window );
}

float timestamp ()
{
  timeb tb;
  ftime( &tb );
  return float( tb.millitm + ( tb.time & 0xfffff ) * 1000 );
}

GLuint createShader ( char* path, int type )
{
  std::ifstream file( path );

  if ( !file ) {
    throw "Can't open shader";
  }

  // write file contents to "const char*"
  const char* src = std::string( ( std::istreambuf_iterator<char>( file ) ), std::istreambuf_iterator<char>() ).c_str();

  // it gives garbage
  std::cout << src << std::endl;

  file.close();

  GLuint shader = glCreateShader( type );

  glShaderSource( shader, 1, &src, nullptr );
  glCompileShader( shader );

  return shader;
}

GLuint createProgram ( GLuint vert, GLuint frag )
{
  GLuint program = glCreateProgram();

  glAttachShader( program, vert );
  glAttachShader( program, frag );

  glLinkProgram( program );

  int attached;

  glGetProgramiv( program, GL_LINK_STATUS, &attached );

  if( !attached ) {
    std::cerr << "Can't attach shaders" << std::endl;
  }
}
