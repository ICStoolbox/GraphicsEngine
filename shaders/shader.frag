#version 130

varying vec3 fragmentColor;


void main(){
  gl_FragColor = vec4(fragmentColor,0.3);
}
