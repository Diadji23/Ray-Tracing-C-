Sphere::Sphere(const Vector3f& origin, float radius) : origin(origin), radius(radius) {}

//utilisation de l'equation quadratique
bool Sphere::isHit(const Ray3f& ray, float& t) const {
    Vector3f oc = ray.origin - origin;
    float a = ray.direction.dot(ray.direction);
    float b = 2.0f * oc.dot(ray.direction);
    float c = oc.dot(oc) - radius * radius;
    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return false; // No intersection
    } else {
        t = (-b - std::sqrt(discriminant)) / (2.0f * a);
        return t > 0; // Intersection exists if t > 0
    }
}

//formule de réflexion
Vector3f Sphere::reflect(const Ray3f& ray, const Vector3f& point) const {
    Vector3f normal = (point - origin).normalize();
    return ray.direction - normal * 2.0f * ray.direction.dot(normal);
}