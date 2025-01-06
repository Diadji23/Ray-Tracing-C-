#include "vector3f.hpp"

Vector3f::Vector3f() : x(0), y(0), z(0) {}

Vector3f::Vector3f(float x, float y, float z) : x(x), y(y), z(z) {}


float Vector3f::getX() const {
    return x;
}


float Vector3f::getY() const {
    return y;
}

float Vector3f::getZ() const {
    return z;
}


Vector3f Vector3f::operator+(const Vector3f& other) const {
    return Vector3f(x + other.getX(), y + other.getY(), z + other.getZ());
}

Vector3f Vector3f::operator-(const Vector3f& other) const {
    return Vector3f(x - other.x, y - other.y, z - other.z);
}

Vector3f Vector3f::operator*(float scalar) const {
    return Vector3f(x * scalar, y * scalar, z * scalar);
}

Vector3f Vector3f::operator*(const Vector3f& other) const {
    return Vector3f(x * other.x, y * other.y, z * other.z);
}

//produit scalaire  
float Vector3f::dot(const Vector3f& other) const {
    return x * other.x + y * other.y + z * other.z;
}
 //produit vectoriel
Vector3f Vector3f::cross(const Vector3f& other) const {
    float x = getX() ; 
    float y = getY() ; 
    float z = getZ() ; 
    return Vector3f(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

//norme
float Vector3f::magnitude() const {
    float x = getX() ; 
    float y = getY() ; 
    float z = getZ() ;

    return std::sqrt(x * x + y * y + z * z);
}

//renvoie un vecteur de norme 1
Vector3f Vector3f::normalize() const {
    float x = getX() ; 
    float y = getY() ; 
    float z = getZ() ;
    float mag = magnitude();
    return Vector3f(x / mag, y / mag, z / mag);

}



Vector3f& Vector3f::clamp(float min_val, float max_val) { 
    x = std::max(min_val, std::min(x, max_val));
    y = std::max(min_val, std::min(y, max_val));
    z = std::max(min_val, std::min(z, max_val));
     return *this; }


Vector3f operator*(float scalar, const Vector3f& vec) { 
    return Vector3f(vec.getX() * scalar, vec.getY() * scalar, vec.getZ() * scalar); }