#include "cube_quad.cpp"

Cub_quad::Cub_quad (const Vector3f& origin_ , const Vector3f& width ,const width)
    :origin_(origin), width_(width), height_(height) {} ;



bool Cub_quad::is_hit(const Ray3f& ray , float& t ) const {
    Vector3f A = origin + Vector3f(-size.x / 2, -size.y / 2, 0); // Bas-gauche
    Vector3f B = origin + Vector3f(size.x / 2, -size.y / 2, 0);  // Bas-droit
    Vector3f C = origin + Vector3f(size.x / 2, size.y / 2, 0);   // Haut-droit
    Vector3f D = origin + Vector3f(-size.x / 2, size.y / 2, 0);  // Haut-gauche

    // Calcul de la normale du plan
    Vector3f normal = (B - A).cross(D - A).normalize();

    // Calcul de l'intersection du rayon avec le plan
    float denom = normal.dot(ray.direction);
    if (std::abs(denom) < 1e-6) {
        // Le rayon est parallèle au plan
        return false;
    }

    float t_plane = (A - ray.origin).dot(normal) / denom;
    if (t_plane < 0) {
        // L'intersection est derrière l'origine du rayon
        return false;
    }

    // Point d'intersection avec le plan
    Vector3f P = ray.point_at(t_plane);

    // Test si le point est dans le quadrilatère
    if (is_point_in_quad(P, A, B, C, D)) {
        t = t_plane;
        return true;
    }

    return false;


};
