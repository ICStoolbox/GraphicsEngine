/****************************************************************
*
* CGL: ICS Graphics Library
*
* Original Authors:
*   J. Foulon, P. Frey
*
****************************************************************/
#ifndef __CGL_VIEW_H_
#define __CGL_VIEW_H_

#include "defs.h"

class CGL_API CglView
{
public:
	double    m_znear,m_zfar;
	double    m_fovy;
	double    ratio;
	int       width, height;
	float     zoom;
	float     camOffset;
	double    m_eyesep;

private:
  bool      m_stereo;

public:
	CglView();
	virtual ~CglView(){};
	void setPersp(double fovy, double znear, double zfar);

	void setView();
	void reshape(int w, int h);
};

typedef CglView * pCglView;


#endif
