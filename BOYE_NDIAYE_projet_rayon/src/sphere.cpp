#include "sphere.hpp"

Sphere::Sphere(const Vector3f& origin, float radius, const Material& material) : origin_(origin), radius_(radius) , material_(material){}

//utilisation de l'equation quadratique
bool Sphere::isHit(const Ray3f& ray, float& t) const {
    Vector3f oc = ray.get_origin() - origin_;
    float a = ray.get_direction().dot(ray.get_direction());
    float b = 2.0f * oc.dot(ray.get_direction());
    float c = oc.dot(oc) - radius_ * radius_;
    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return false; // No intersection
    } else {
        t = (-b - std::sqrt(discriminant)) / (2.0f * a);
        return t > 0; // Intersection exists if t > 0
    }
}

Material Sphere::get_material() const {
    return material_ ; 
}

//formule de réflexion
Vector3f Sphere::reflect(const Ray3f& ray, const Vector3f& point) const {
    Vector3f normal = (point - origin_).normalize();
    return ray.get_direction() - normal * 2.0f * ray.get_direction().dot(normal);
}

