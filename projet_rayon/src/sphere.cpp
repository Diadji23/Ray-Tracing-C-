#include "sphere.hpp"

Sphere::Sphere(const Vector3f& origin, float radius, const Material& material) : origin_(origin), radius_(radius) , material_(material){}



bool Sphere::isHit(const Ray3f& ray, float& t, Vector3f& intersection_point, Vector3f& normal) const {
    Vector3f oc = ray.get_origin() - origin_; // Vecteur entre le centre de la sphère et l'origine du rayon

    float a = ray.get_direction().dot(ray.get_direction());
    float b = 2.0f * oc.dot(ray.get_direction());
    float c = oc.dot(oc) - radius_ * radius_;

    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return false; // Pas d'intersection
    }

    // Calcul des racines de l'équation quadratique
    float sqrt_discriminant = std::sqrt(discriminant);
    float t1 = (-b - sqrt_discriminant) / (2.0f * a);
    float t2 = (-b + sqrt_discriminant) / (2.0f * a);

    // Choisir la plus proche intersection dans la direction du rayon
    if (t1 > 1e-6) {
        t = t1;
    } else if (t2 > 1e-6) {
        t = t2;
    } else {
        return false; // Les intersections sont derrière le rayon
    }

    // Calcul du point d'intersection et de la normale
    intersection_point = ray.get_origin() + t * ray.get_direction();
    normal = (intersection_point - origin_).normalize(); // Normale pointant vers l'extérieur
    return true;
}


Material Sphere::get_material() const {
    return material_ ; 
}

//formule de réflexion
/*Vector3f Sphere::reflect(const Ray3f& ray, const Vector3f& point) const {
    Vector3f normal = (point - origin_).normalize();
    return ray.get_direction() - normal * 2.0f * ray.get_direction().dot(normal);
}*/

Vector3f Sphere::get_origin() const{
    return origin_ ; 
}

Vector3f Sphere::get_height() const {
    return Vector3f(0.0f, 0.0f , 0.0f) ; 
};
Vector3f Sphere::get_width() const {
    return Vector3f(0.0f, 0.0f , 0.0f) ; 
} ; 