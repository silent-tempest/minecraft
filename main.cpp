#include <iostream>
#include <GL/glut.h>
// THANKS MINGW!
// WHY YOU NOT SEARCHING FILES IN THE PROJECT??????
#include "src/Ticker.h"

float r = 0,
      g = 0,
      b = 0;

void render ();
void changeColor ();

int main ( int argc, char** argv )
{
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB );
  glutCreateWindow( "Minecraft" );
  glutFullScreen();
  glutDisplayFunc( render );
  glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
  glEnable( GL_BLEND );
  changeColor();
  glutMainLoop();
  return 0;
}

void render ()
{
  glClearColor( r, g, b, 1.0 );
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glutSwapBuffers();
  changeColor();
}

void changeColor ()
{
  r +- 0.1f;
  g +- 0.1f;
  b +- 0.1f;
}
