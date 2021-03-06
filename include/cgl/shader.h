#ifndef SHADERHEADERDEF
#define SHADERHEADERDEF

#include "defs.h"

class CglShader
{
private:
  std::string mVertex_file_path;
  std::string mFragment_file_path;

public:
  GLuint      mProgramID;
  CglShader();
  void load(std::string vert_file_path, std::string frag_file_path, std::string functions_file_path);
  void load(std::string TYPE);
};

typedef CglShader* pCglShader;

#endif
