#ifndef SHAPE_H
#define SHAPE_H

#include "Vector3f.h"
#include "Ray3f.h"

class Shape {
public:
    virtual bool isHit(const Ray3f& ray) const ;
    virtual Vector3f reflect(const Ray3f& ray) const;
    virtual ~Shape() {}
};

#endif