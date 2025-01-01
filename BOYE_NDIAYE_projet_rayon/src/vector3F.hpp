#ifndef VECTOR3F_H
#define VECTOR3F_H

#include <cmath>

class Vector3f {
public:
    float x, y, z;

    Vector3f();
    Vector3f(float x, float y, float z);

    Vector3f operator+(const Vector3f& other) const;
    Vector3f operator-(const Vector3f& other) const;
    Vector3f operator*(float scalar) const;
    float dot(const Vector3f& other) const;
    Vector3f cross(const Vector3f& other) const;
    float magnitude() const;
    Vector3f normalize() const;
};

#endif