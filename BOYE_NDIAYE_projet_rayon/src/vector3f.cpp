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


#include <iostream>
#include "vector3f.hpp"

void test_vector3f() {
    // Test du constructeur par défaut
    Vector3f v1;
    std::cout << "Test constructeur par défaut : " << v1.getX() << ", " << v1.getY() << ", " << v1.getZ() << std::endl;
    //test contructeur valué

    Vector3f v2(1.0f , 2.0f , 3.0f); 

    std::cout << "test constructeur param " <<v2.getX() << v2.getY() <<" " << v2.getZ() << std::endl ; 

    // Test de l'opération d'addition
    Vector3f v3 = v1 + v2;
    std::cout << "Test addition : " << v3.getX() << ", " << v3.getY() << ", " << v3.getZ() << std::endl;

    // Test de l'opération de soustraction
    Vector3f v4 = v2 - v3;
    std::cout << "Test soustraction : " << v4.getX() << ", " << v4.getY()<< ", " << v4.getZ() << std::endl;
std::cout << "Test de la normalisation" << std::endl;

    // Vecteur non nul
    Vector3f v(3.0f, 4.0f, 0.0f); // Magnitude = 5
    Vector3f v1_normalized = v.normalize();
    std::cout << "Vecteur initial : (" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")" << std::endl;
    std::cout << "Vecteur normalisé : (" << v1_normalized.getX() << ", " << v1_normalized.getY() << ", " << v1_normalized.getZ() << ")" << std::endl;
    std::cout << "Norme du vecteur normalisé : " << v1_normalized.magnitude() << std::endl;

    // Vecteur nul
    // Test de la multiplication scalaire
    Vector3f v5 = v2 * 2.0f;
    std::cout << "Test multiplication scalaire : " << v5.getX() << ", " << v5.getY() << ", " << v5.getZ() << std::endl;
    // 
    // Test du produit scalaire
    float dotProduct = v2.dot(v5);
    std::cout << "Test produit scalaire : " << dotProduct << std::endl;

    // Test du produit vectoriel
    Vector3f crossProduct = v2.cross(v5);
    std::cout << "Test produit vectoriel : " << crossProduct.getX() << ", " << crossProduct.getY() << ", " << crossProduct.getZ() << std::endl;

} 

