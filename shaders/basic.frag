uniform vec4 color;

void main ()
{
  gl_FragColor = vec4( color.rgb / 255.0, color.a );
}
