#include "Vector3f.h"

Vector3f::Vector3f() : x(0), y(0), z(0) {}
Vector3f::Vector3f(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3f Vector3f::operator+(const Vector3f& other) const {
    return Vector3f(x + other.x, y + other.y, z + other.z);
}

Vector3f Vector3f::operator-(const Vector3f& other) const {
    return Vector3f(x - other.x, y - other.y, z - other.z);
}

Vector3f Vector3f::operator*(float scalar) const {
    return Vector3f(x * scalar, y * scalar, z * scalar);
}

//produit scalaire
float Vector3f::dot(const Vector3f& other) const {
    return x * other.x + y * other.y + z * other.z;
}
 //produit vectoriel
Vector3f Vector3f::cross(const Vector3f& other) const {
    return Vector3f(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}
//norme
float Vector3f::magnitude() const {
    return std::sqrt(x * x + y * y + z * z);
}

//renvoie un vecteur de norme 1
Vector3f Vector3f::normalize() const {
    float mag = magnitude();
    return Vector3f(x / mag, y / mag, z / mag);
}