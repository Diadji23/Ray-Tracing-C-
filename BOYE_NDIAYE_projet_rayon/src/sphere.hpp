#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"

class Sphere : public Shape {
public:
    Vector3f origin;
    float radius;

    Sphere(const Vector3f& origin, float radius);
    bool isHit(const Ray3f& ray, float& t) const override;
    Vector3f reflect(const Ray3f& ray, const Vector3f& point) const override;
};

#endif