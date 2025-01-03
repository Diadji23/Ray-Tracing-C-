#include "cube_quad.hpp"


//constructeur

Cub_quad::Cub_quad (const Vector3f& origin , const Vector3f& width ,const Vector3f& height, const Material& material)
    :origin_(origin), width_(width), height_(height) , material_(material){} ;


//intersection
bool Cub_quad::is_hit(const Ray3f& ray , float& t ) const {
    Vector3f A = origin_ ;
    Vector3f B = origin_ + width_  ; 
    Vector3f C = origin_ + width_ + height_ ; 
    Vector3f D = origin_ +  height_ ; 

    // Calcul de la normale du plan
    Vector3f normal = (B - A).cross(D - A).normalize();

    // Calcul de l'intersection du rayon avec le plan
    float denom = normal.dot(ray.direction_);
    if (std::abs(denom) < 1e-6) {
        // Le rayon est parallèle au plan
        return false;
    }

    float t_plane = (A - ray.origin_).dot(normal) / denom;
    if (t_plane < 0) {
        // L'intersection est derrière l'origine du rayon
        return false;
    }

    // Point d'intersection avec le plan
    Vector3f P = ray.point_at(t_plane);

    / Vérifier si le point est dans le quadrilatère
    Vector3f AP = P - A;
    Vector3f AB = B - A;
    Vector3f AD = D - A;

    float ab_dot_ab = AB.dot(AB);
    float ab_dot_ap = AB.dot(AP);
    float ad_dot_ad = AD.dot(AD);
    float ad_dot_ap = AD.dot(AP);

    if (0 <= ab_dot_ap && ab_dot_ap <= ab_dot_ab && 0 <= ad_dot_ap && ad_dot_ap <= ad_dot_ad) {
        t = t_plane;
        return true;
    }

    return false;


}

//le materiau

Material Cub_quad::get_material() const override { return material_; }


int main() {
    return 0 ; 
    
}