attribute vec2 pos;
uniform   vec2 res;
uniform   mat3 transform;

void main ()
{
  gl_Position = vec4( ( ( transform * vec3( pos, 1.0 ) ).xy / res * 2.0 - 1.0 ) * vec2( 1.0, -1.0 ), 0.0, 1.0 );
}
