#ifndef PROFILE_H
#define PROFILE_H

#include "defs.h"
#include "cgl/colorgenerator.h"

class CglProfile
{
  public:
    //Constructor from config file
    CglProfile();
    ~CglProfile();
    glm::vec3 color();
    void update_theme();

  public:
    CglColorGenerator colorGenerator;

    bool  displayShadows;
    bool  displayBottomGrid;
    bool  displayAxes;
    bool  displayAxesLabels;

    bool  perspective;

    bool  flyingMode;
    bool  classicalMode;
    bool  accumulatedMode;

    bool  stereo;

    float bottomDistance;
    float bottomAngle;

    bool  invertVertical;
    bool  independantScale;
    bool  globalScale;
    bool  groupRotation;

    bool dark_theme;
    glm::vec3 dark_back_color,  dark_grid_color,  dark_idle_color;
    glm::vec3 clear_back_color, clear_grid_color, clear_idle_color;
    glm::vec3 back_color,       grid_color,       idle_color;
    float     dark_shadow,      clear_shadow,     shadow_factor;
    glm::vec3 sele_color;

  protected:
  private:
};

#endif // PROFILE_H
