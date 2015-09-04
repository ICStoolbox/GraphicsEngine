#include "cgl/profile.h"

CglProfile::CglProfile()
{
  displayShadows    = true;
  displayBottomGrid = true;
  displayAxes       = true;
  displayAxesLabels = false;

  stereo            = false;

  perspective       = true;

  classicalMode     = true;
  accumulatedMode   = false;
  flyingMode        = false;

  invertVertical    = true;

  independantScale  = false;
  globalScale       = true;

  groupRotation     = true;

  bottomDistance    = 0.1;
  bottomAngle       = (float)3.14159/4;

  clear_back_color    = glm::vec3(1,   1,   0.98);
  clear_grid_color    = glm::vec3(0.5, 0.5, 0.5);
  clear_idle_color    = glm::vec3(0.7, 0.7, 0.7);
  clear_shadow        = 0.9;

  dark_back_color    = glm::vec3(0.01, 0.01, 0);
  dark_grid_color    = glm::vec3(0.2, 0.2, 0.2);
  dark_idle_color    = glm::vec3(0.3, 0.3, 0.3);
  dark_shadow        = 0.2;

  bool dark_theme = true;
  update_theme();

  sele_color    = glm::vec3(1,   0.6, 0);
}

CglProfile::~CglProfile(){}

glm::vec3 CglProfile::color(){
  return colorGenerator.generateColor();
}

void CglProfile::update_theme(){
  back_color    = ((dark_theme)?dark_back_color:clear_back_color);
  grid_color    = ((dark_theme)?dark_grid_color:clear_grid_color);
  idle_color    = ((dark_theme)?dark_idle_color:clear_idle_color);
  shadow_factor = ((dark_theme)?dark_shadow:clear_shadow);
}
