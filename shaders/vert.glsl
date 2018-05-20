attribute vec2 a_position;
uniform vec2 u_resolution;
uniform mat3 u_transform;

void main ()
{
  gl_Position = vec4( ( ( u_transform * vec3( a_position, 1.0 ) ).xy / u_resolution * 2.0 - 1.0 ) * vec2( 1, -1 ), 0, 1 );
}
