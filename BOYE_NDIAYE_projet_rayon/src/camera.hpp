#ifndef CAMERA_H
#define CAMERA_H

#include "vector3f.hpp"

class Camera {
public:
    Vector3f position_;
    Vector3f direction_;
private :
    Camera() ; 
    Camera(const Vector3f& position, const Vector3f& direction);
    //
  

};

#endif