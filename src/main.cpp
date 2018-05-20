/**
 * Compile: g++ -o main.deb src/main.cpp -lGL -lGLEW -lglfw
 */

#include <iostream>      // std::cout, std::endl
#include <fstream>       // std::ifstream
#include <sstream>       // std::stringstream
#include <streambuf>     // std::istreambuf_iterator
#include <sys/timeb.h>   // ftime
#include <algorithm>     // std::min
#include <exception>     // std::exception
#include <GL/glew.h>     // GLEW
#include <GLFW/glfw3.h>  // Use GLFW to create a window
#include <GL/freeglut.h> // OpenGL

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
    std::cerr << "Unable to initialize GLFW" << std::endl;
  }

  glfwSetErrorCallback( error );

  glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 2 );
  glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 0 );

  window = glfwCreateWindow( 640, 480, "Minecraft", nullptr, nullptr );

  if ( !window ) {
    std::cerr << "Unable to create a window" << std::endl;
  }

  glfwMakeContextCurrent( window );

  // glewInit returns 0 if no error
  if ( glewInit() ) {
    std::cerr << "Unable to initialize GLEW" << std::endl;
  }

  GLuint vert = createShader( "shaders/vert.glsl", GL_VERTEX_SHADER ),
         frag = createShader( "shaders/frag.glsl", GL_FRAGMENT_SHADER );

  program = createProgram( vert, frag );

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
  float lastTime = timestamp(),
        skippedTime = 0,
        totalTime = 0,
        step = 1.0f / 60.0f;

  stopped = false;

  do {
    float now = timestamp(),
          dt = std::min( 1.0f, ( now - lastTime ) / 1000 );

    skippedTime += dt;
    totalTime += dt;

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
    std::cerr << "Unable to open shader" << std::endl;
  }

  std::string srcstr = std::string( ( std::istreambuf_iterator<char>( file ) ), std::istreambuf_iterator<char>() );

  const GLchar* src = srcstr.c_str();

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

  int ok;

  glLinkProgram( program );
  glGetProgramiv( program, GL_LINK_STATUS, &ok );

  if ( !ok ) {
    std::cerr << "Unable to initialize the shader program" << std::endl;
  }

  glValidateProgram( program );
  glGetProgramiv( program, GL_VALIDATE_STATUS, &ok );

  if ( !ok ) {
    std::cerr << "Unable to validate the shader program" << std::endl;
  }

  return program;
}
