#include "ray3f.hpp"
#include <iostream>




Ray3f::Ray3f() : origin_(0.0f, 0.0f, 0.0f), direction_(1.0f, 0.0f, 0.0f) {}

   
Ray3f::Ray3f(const Vector3f& origin, const Vector3f& direction)
    : origin_(origin), direction_(direction.normalize()) {}


    
Vector3f Ray3f::point_at(float t) const {
    return origin_ + direction_ * t;
}


