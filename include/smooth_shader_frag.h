// header file generated by txt2h, 2003-2006 by ScottManDeath
#ifndef  TXT_HEADER_smooth_frag_code
#define  TXT_HEADER_smooth_frag_code


const char smooth_frag_code [] =
"#version 120\n"
"\n"
"varying vec3 vertex_pos;\n"
"varying vec3 vertex_nor;\n"
"\n"
"uniform mat4 MVP;\n"
"uniform vec3 COL;\n"
"uniform mat4 FILL;\n"
"uniform mat4 SIDE;\n"
"uniform mat4 BACK;\n"
"uniform mat4 M;\n"
"uniform mat4 V;\n"
"uniform vec3 FOG_COL;\n"
"uniform float FOG;\n"
"\n"
"vec3  smoothLight(mat4 light_matrix, vec3 mater_color);\n"
"float fog(float begin, float end);\n"
"vec3  fog(vec3 col){\n"
"    if(FOG==1.0f){\n"
"        vec3 newCol;\n"
"        float f        = fog(2.5, 4.0);\n"
"        newCol         = (1-f)*FOG_COL + f*col;\n"
"        return newCol;\n"
"    }\n"
"    else\n"
"        return col;\n"
"}\n"
"\n"
"float snoise(vec3 v);\n"
"float fbm(vec3 val, float initFreq, float gain, int octaves, float lacunarity);\n"
"\n"
"\n"
"void main(){\n"
"  vec3 Position_worldspace = (M * vec4(vertex_pos,1)).xyz;\n"
"  vec3 col = smoothLight(FILL, COL) + smoothLight(SIDE, COL) + smoothLight(BACK, COL);\n"
"  //gl_FragColor = vec4(col, 0.3);\n"
"\n"
"  //Second try for noise\n"
"  float N       = fbm(vertex_pos, 0.07f, 0.75, 8, 1.9f);//snoise(10 * vertex_pos);\n"
"  float F       = 0.8*(N-0.5) + 0.5;\n"
"  vec3 finalCol = fog( F*col + (1-F)*0.9*col );\n"
"  gl_FragColor  = vec4(finalCol, 0.0);// * vec4(col,0.3);//vec4(noise3D, 0.3);\n"
"}\n"
"\n"
"\n"
"float fog(float begin, float end){\n"
"    float d   = length(( V * M * vec4(vertex_pos,1)).xyz);\n"
"    float fac;\n"
"    //Linear\n"
"    //fac = (end - d)/(end - begin);\n"
"    //Exponential\n"
"    float FogDensity = 1.3;\n"
"    if(d>begin)\n"
"        fac = 1.0 /exp( ((d-begin) * FogDensity)* ((d-begin) * FogDensity));\n"
"    else\n"
"        fac = 1;\n"
"\n"
"    fac = clamp( fac, 0.0, 1.0 );\n"
"    return fac;\n"
"}\n"
"\n"
"vec3 smoothLight(mat4 light_matrix, vec3 mater_color){\n"
"  vec3  light_posit     = light_matrix[0].xyz;\n"
"  vec3  light_color     = light_matrix[1].xyz;\n"
"  vec3  mix_ratio       = light_matrix[2].xyz;\n"
"  float light_power     = light_matrix[3].x;\n"
"  float lobe_size       = light_matrix[3].y;\n"
"  bool  camera_anchored = bool(light_matrix[3].z);\n"
"\n"
"  float distance = length(light_posit - (MVP * vec4(vertex_pos,1)).xyz);\n"
"  vec3 vertex_position_cameraspace = ( V * M * vec4(vertex_pos,1)).xyz;\n"
"  vec3 eye_direction_cameraspace = vec3(0,0,0) - vertex_position_cameraspace;\n"
"  vec3 light_position_cameraspace = ( V * vec4(light_posit,1)).xyz;\n"
"\n"
"  //WORLD OR CAMERA?\n"
"  vec3 light_direction_cameraspace;\n"
"  if(camera_anchored)\n"
"    light_direction_cameraspace = light_posit + eye_direction_cameraspace;\n"
"  else\n"
"    light_direction_cameraspace = light_position_cameraspace + eye_direction_cameraspace;\n"
"\n"
"  vec3 normal_cameraspace = ( V * M * vec4(vertex_nor,0)).xyz;\n"
"  vec3 n = normalize( normal_cameraspace );\n"
"  vec3 l = normalize( light_direction_cameraspace );\n"
"  float cosTheta = clamp( dot( n,l ), 0.,1. );\n"
"\n"
"  vec3 E = normalize(eye_direction_cameraspace);\n"
"  vec3 R = reflect(-l,n);\n"
"  float cosAlpha = clamp( dot( E,R ), 0.,1. );\n"
"\n"
"  vec3 ambi_color = 0.1 *  mater_color;\n"
"  vec3 diff_color = mater_color;\n"
"  vec3 spec_color = 0.5 * (mater_color + vec3(1.0, 1.0, 1.0));\n"
"  vec3 color = mix_ratio.x * ambi_color\n"
"             + mix_ratio.y * diff_color * light_color * light_power * cosTheta        / (distance*distance)\n"
"             + mix_ratio.z * spec_color * light_color * light_power * pow(cosAlpha,lobe_size) / (distance*distance)\n"
"             ;\n"
"\n"
"  return color;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"float fbm(vec3 val, float initFreq, float gain, int octaves, float lacunarity){\n"
"    float total = 0.0f;\n"
"    float frequency = 1.0f/initFreq;\n"
"    float amplitude = gain;\n"
"    for (int i = 0; i < octaves; i++){\n"
"        total += snoise(val * frequency) * amplitude;\n"
"        frequency *= lacunarity;\n"
"        amplitude *= gain;\n"
"    }\n"
"    return total;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"//\n"
"// Description : Array and textureless GLSL 2D/3D/4D simplex\n"
"//               noise functions.\n"
"//      Author : Ian McEwan, Ashima Arts.\n"
"//  Maintainer : ijm\n"
"//     Lastmod : 20110822 (ijm)\n"
"//     License : Copyright (C) 2011 Ashima Arts. All rights reserved.\n"
"//               Distributed under the MIT License. See LICENSE file.\n"
"//               https://github.com/ashima/webgl-noise\n"
"//\n"
"\n"
"vec3 mod289(vec3 x) {\n"
"  return x - floor(x * (1.0 / 289.0)) * 289.0;\n"
"}\n"
"\n"
"vec4 mod289(vec4 x) {\n"
"  return x - floor(x * (1.0 / 289.0)) * 289.0;\n"
"}\n"
"\n"
"vec4 permute(vec4 x) {\n"
"     return mod289(((x*34.0)+1.0)*x);\n"
"}\n"
"\n"
"vec4 taylorInvSqrt(vec4 r)\n"
"{\n"
"  return 1.79284291400159 - 0.85373472095314 * r;\n"
"}\n"
"\n"
"float snoise(vec3 v)\n"
"  {\n"
"  const vec2  C = vec2(1.0/6.0, 1.0/3.0) ;\n"
"  const vec4  D = vec4(0.0, 0.5, 1.0, 2.0);\n"
"\n"
"// First corner\n"
"  vec3 i  = floor(v + dot(v, C.yyy) );\n"
"  vec3 x0 =   v - i + dot(i, C.xxx) ;\n"
"\n"
"// Other corners\n"
"  vec3 g = step(x0.yzx, x0.xyz);\n"
"  vec3 l = 1.0 - g;\n"
"  vec3 i1 = min( g.xyz, l.zxy );\n"
"  vec3 i2 = max( g.xyz, l.zxy );\n"
"\n"
"  //   x0 = x0 - 0.0 + 0.0 * C.xxx;\n"
"  //   x1 = x0 - i1  + 1.0 * C.xxx;\n"
"  //   x2 = x0 - i2  + 2.0 * C.xxx;\n"
"  //   x3 = x0 - 1.0 + 3.0 * C.xxx;\n"
"  vec3 x1 = x0 - i1 + C.xxx;\n"
"  vec3 x2 = x0 - i2 + C.yyy; // 2.0*C.x = 1/3 = C.y\n"
"  vec3 x3 = x0 - D.yyy;      // -1.0+3.0*C.x = -0.5 = -D.y\n"
"\n"
"// Permutations\n"
"  i = mod289(i);\n"
"  vec4 p = permute( permute( permute(\n"
"             i.z + vec4(0.0, i1.z, i2.z, 1.0 ))\n"
"           + i.y + vec4(0.0, i1.y, i2.y, 1.0 ))\n"
"           + i.x + vec4(0.0, i1.x, i2.x, 1.0 ));\n"
"\n"
"// Gradients: 7x7 points over a square, mapped onto an octahedron.\n"
"// The ring size 17*17 = 289 is close to a multiple of 49 (49*6 = 294)\n"
"  float n_ = 0.142857142857; // 1.0/7.0\n"
"  vec3  ns = n_ * D.wyz - D.xzx;\n"
"\n"
"  vec4 j = p - 49.0 * floor(p * ns.z * ns.z);  //  mod(p,7*7)\n"
"\n"
"  vec4 x_ = floor(j * ns.z);\n"
"  vec4 y_ = floor(j - 7.0 * x_ );    // mod(j,N)\n"
"\n"
"  vec4 x = x_ *ns.x + ns.yyyy;\n"
"  vec4 y = y_ *ns.x + ns.yyyy;\n"
"  vec4 h = 1.0 - abs(x) - abs(y);\n"
"\n"
"  vec4 b0 = vec4( x.xy, y.xy );\n"
"  vec4 b1 = vec4( x.zw, y.zw );\n"
"\n"
"  //vec4 s0 = vec4(lessThan(b0,0.0))*2.0 - 1.0;\n"
"  //vec4 s1 = vec4(lessThan(b1,0.0))*2.0 - 1.0;\n"
"  vec4 s0 = floor(b0)*2.0 + 1.0;\n"
"  vec4 s1 = floor(b1)*2.0 + 1.0;\n"
"  vec4 sh = -step(h, vec4(0.0));\n"
"\n"
"  vec4 a0 = b0.xzyw + s0.xzyw*sh.xxyy ;\n"
"  vec4 a1 = b1.xzyw + s1.xzyw*sh.zzww ;\n"
"\n"
"  vec3 p0 = vec3(a0.xy,h.x);\n"
"  vec3 p1 = vec3(a0.zw,h.y);\n"
"  vec3 p2 = vec3(a1.xy,h.z);\n"
"  vec3 p3 = vec3(a1.zw,h.w);\n"
"\n"
"//Normalise gradients\n"
"  vec4 norm = taylorInvSqrt(vec4(dot(p0,p0), dot(p1,p1), dot(p2, p2), dot(p3,p3)));\n"
"  p0 *= norm.x;\n"
"  p1 *= norm.y;\n"
"  p2 *= norm.z;\n"
"  p3 *= norm.w;\n"
"\n"
"// Mix final noise value\n"
"  vec4 m = max(0.6 - vec4(dot(x0,x0), dot(x1,x1), dot(x2,x2), dot(x3,x3)), 0.0);\n"
"  m = m * m;\n"
"  return 42.0 * dot( m*m, vec4( dot(p0,x0), dot(p1,x1),\n"
"                                dot(p2,x2), dot(p3,x3) ) );\n"
"  }\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
;


#endif  // #ifdef TXT_HEADER_smooth_frag_code