#ifndef SHAPE_H
#define SHAPE_H

#include "vector3f.hpp"
#include "ray3f.hpp"

class Shape {
public:
    virtual bool isHit(const Ray3f& ray) const ;
    virtual Vector3f reflect(const Ray3f& ray) const;
    virtual ~Shape() {}
};

#endif