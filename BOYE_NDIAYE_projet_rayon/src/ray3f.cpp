#include "ray3f.hpp"
#include <iostream>





Ray3f::Ray3f() : origin_(0.0f, 0.0f, 0.0f), direction_(1.0f, 0.0f, 0.0f) {}

   
Ray3f::Ray3f(const Vector3f& origin, const Vector3f& direction)
    : origin_(origin), direction_(direction.normalize()) {}


    
Vector3f Ray3f::point_at(float t) const {
    return origin_ + direction_ * t;
}

/**
 * @brief Teste le constructeur par défaut de Ray3f.
 */
void test_default_constructor1() {
    Ray3f ray;
    std::cout << "Test constructeur par défaut:" << std::endl;
    std::cout << "Origine : (" << ray.point_at(0).x << ", " 
              << ray.point_at(0).y << ", " << ray.point_at(0).z << ")" << std::endl;
}

/**
 * @brief Teste le constructeur avec paramètres de Ray3f.
 */
void test_param_constructor1() {
    Vector3f origin(1.0f, 2.0f, 3.0f);
    Vector3f direction(4.0f, 5.0f, 6.0f);
    Ray3f ray(origin, direction);
    std::cout << "Test constructeur avec paramètres:" << std::endl;

}

