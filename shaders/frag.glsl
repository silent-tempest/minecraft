uniform vec4 u_color;

void main ()
{
  gl_FragColor = vec4( u_color.rgb / 255.0, u_color.a );
}
