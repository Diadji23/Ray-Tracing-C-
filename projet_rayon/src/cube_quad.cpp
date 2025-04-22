#include "cube_quad.hpp"
#include "vector3f.hpp"
#include <iostream>

//constructeur

Cub_quad::Cub_quad (const Vector3f& origin , const Vector3f& width ,const Vector3f& height, const Material& material)
    :origin_(origin), width_(width), height_(height) , material_(material){} ;





bool Cub_quad::isHit(const Ray3f& ray, float& t, Vector3f& intersection_point, Vector3f& normal) const {
    // Points du quadrilatère
    Vector3f A = origin_;
    Vector3f B = origin_ + width_;
    Vector3f D = origin_ + height_;

    // Calcul de la normale du plan
    normal = (B - A).cross(D - A).normalize();

    // Intersection avec le plan
    float denom = normal.dot(ray.get_direction());
    if (std::abs(denom) < 1e-6) {
        return false; // Le rayon est parallèle au plan
    }

    float t_plane = (A - ray.get_origin()).dot(normal) / denom;
    if (t_plane < 0) {
        return false; // L'intersection est derrière l'origine du rayon
    }

    // Calcul du point d'intersection
    Vector3f P = ray.point_at(t_plane);

    // Vérification si P est à l'intérieur du quadrilatère
    Vector3f AP = P - A;
    Vector3f AB = B - A;
    Vector3f AD = D - A;

    float ab_dot_ab = AB.dot(AB);
    float ab_dot_ap = AB.dot(AP);
    float ad_dot_ad = AD.dot(AD);
    float ad_dot_ap = AD.dot(AP);

    if (0 <= ab_dot_ap && ab_dot_ap <= ab_dot_ab && 0 <= ad_dot_ap && ad_dot_ap <= ad_dot_ad) {
        t = t_plane;
        intersection_point = P;
        return true;
    }

    return false; // Le point est à l'extérieur du quadrilatère
}





//Material Cub_quad::get_material() const  { return material_; }

Material Cub_quad::get_material() const {
    return material_;
}



/*Vector3f Cub_quad::reflect(const Ray3f& ray, const Vector3f& point) const 
{ 
    Vector3f normal = (width_.cross(height_)).normalize();
    return ray.get_direction() - normal * 2 * ray.get_direction().dot(normal);
 }
*/
Vector3f Cub_quad::get_origin() const{
    return origin_ ; 
};

Vector3f Cub_quad::get_height() const{
    return height_ ; 
};
Vector3f Cub_quad::get_width() const{
    return width_ ; 
};
