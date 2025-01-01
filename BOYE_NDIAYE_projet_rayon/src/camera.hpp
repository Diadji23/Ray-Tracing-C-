#ifndef CAMERA_H
#define CAMERA_H

#include "Vector3f.h"

class Camera {
public:
    Vector3f position;
    Vector3f direction;

    Camera(const Vector3f& position, const Vector3f& direction);
};

#endif