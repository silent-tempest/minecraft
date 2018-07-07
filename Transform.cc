#include "Transform.h"
#include "mat3.h"

Transform::Transform ()
{
  mat3::set_identity( matrix );
}

Transform::~Transform ()
{
  for ( int i = stack.size() - 1; i >= 0; --i ) {
    delete stack[ i ];
  }
}

void Transform::push ()
{
  if ( ++index < ( int ) stack.size() ) {
    mat3::copy( stack[ index ], matrix );
  } else {
    float* clone = new float[ 9 ];
    mat3::copy( clone, matrix );
    stack.push_back( clone );
  }
}

void Transform::pop ()
{
  if ( index >= 0 ) {
    mat3::copy( matrix, stack[ index-- ] );
  } else {
    mat3::set_identity( matrix );
  }
}

void Transform::set_transform ( float m11, float m12, float m21, float m22, float dx, float dy )
{
  mat3::set_transform( matrix, m11, m12, m21, m22, dx, dy );
}

void Transform::translate ( float x, float y )
{
  mat3::translate( matrix, x, y );
}

void Transform::rotate ( float angle )
{
  mat3::rotate( matrix, angle );
}

void Transform::scale ( float x, float y )
{
  mat3::scale( matrix, x, y );
}

void Transform::transform ( float m11, float m12, float m21, float m22, float dx, float dy )
{
  mat3::transform( matrix, m11, m12, m21, m22, dx, dy );
}
