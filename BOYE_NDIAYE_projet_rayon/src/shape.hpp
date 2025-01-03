#ifndef SHAPE_H
#define SHAPE_H

#include "vector3f.hpp"
#include "ray3f.hpp"

class Shape {
public:
    virtual bool is_hit(const Ray3f& ray, float& t) const = 0  ;
    virtual ~Shape()  = 0 ;
};


#endif

