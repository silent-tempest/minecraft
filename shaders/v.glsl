attribute vec2 aPosition;
uniform   vec2 uResolution;
uniform   mat3 uTransform;

void main ()
{
  gl_Position = vec4( ( ( uTransform * vec3( aPosition, 1.0 ) ).xy / uResolution * 2.0 - 1.0 ) * vec2( 1, -1 ), 0, 1 );
}
