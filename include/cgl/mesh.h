/****************************************************************
 *
 * CGL: ICS Graphics Library
 *
 * Original Authors:
 *   J. Foulon, P. Frey
 *
 ****************************************************************/
#ifndef __CGL_MESH_H_
#define __CGL_MESH_H_

#include <cgl/object.h>

#define FLOAT_MAX  1.e20

typedef struct {
  double    c[3];
  int       ref;
} Point;
//typedef Point * pPoint;

typedef struct {
  int       v[3],ref;
} Tria;
//typedef Tria * pTria;

typedef struct {
  double    n[3];
} Normal;
//typedef Normal * pNormal;

typedef struct {
  int inds[2];
} NormalAtVertex;


class CGL_API CglMesh : public CglObject
{

private:
  int np,nt,nn,dim,ver, nNAtV;
  //Pas nécessaire de les conserver en mémoire si uniquement du display, on peut garder le système de buffer
  vector<Point>    point;
  vector<Tria>     tria;
  vector<Normal>   normal;
  vector<NormalAtVertex> NormalAtVertices;
  GLuint bboxBuffer;
  GLuint bboxIndBuffer;
  GLuint normalBuffer;
  glm::vec3 bbmin, bbmax;
  glm::vec3 tra;


public:
  CglMesh(char *name);
  void meshInfo(const int& verbose = 0, ostream& outstr = cout);
  void shadowsDisplay();
  void artifactsDisplay();
  void display();
  void getBBOX();
  void displayBBOX();
  ~CglMesh(){};

  glm::vec3 getBBMIN(){return center + glm::vec3(glm::inverse(MODEL) * glm::vec4(bbmin, 0));};
  glm::vec3 getBBMAX(){return center + glm::vec3(glm::inverse(MODEL) * glm::vec4(bbmax, 0));};
};

typedef CglMesh* pCglMesh;

#endif
