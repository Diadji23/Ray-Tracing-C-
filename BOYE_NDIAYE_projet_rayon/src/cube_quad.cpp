#include "cube_quad.hpp"
#include "vector3f.hpp"
#include <iostream>

//constructeur

Cub_quad::Cub_quad (const Vector3f& origin , const Vector3f& width ,const Vector3f& height, const Material& material)
    :origin_(origin), width_(width), height_(height) , material_(material){} ;

//destructeur 
Cub_quad::~Cub_quad(){}

//intersection
bool Cub_quad::is_hit(const Ray3f& ray , float& t ) const {
    Vector3f A = origin_ ;
    Vector3f B = origin_ + width_  ;  
    Vector3f D = origin_ +  height_ ; 

    // Calcul de la normale du plan
    Vector3f normal = (B - A).cross(D - A).normalize();

    // Calcul de l'intersection du rayon avec le plan
    float denom = normal.dot(ray.get_direction());
    if (std::abs(denom) < 1e-6) {
        // Le rayon est parallèle au plan
        return false;
    }

    float t_plane = (A - ray.get_origin()).dot(normal) / denom;
    if (t_plane < 0) {
        // L'intersection est derrière l'origine du rayon
        return false;
    }

    // Point d'intersection avec le plan
    Vector3f P = ray.point_at(t_plane);

    //Vérifier si le point est dans le quadrilatère
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

//Material Cub_quad::get_material() const  { return material_; }




//test

void test_is_hit() {
    std::cout << "Test de is_hit sur un quadrilatère" << std::endl;

    // Rayon qui intersecte
    Ray3f ray(Vector3f(1.0f, 1.0f, -1.0f), Vector3f(0.0f, 0.0f, 1.0f));

    // Quadrilatère dans le plan z = 0
    Cub_quad quad(
        Vector3f(0.0f, 0.0f, 0.0f), // Origine
        Vector3f(2.0f, 0.0f, 0.0f), // Largeur
        Vector3f(0.0f, 2.0f, 0.0f), // Hauteur
        Material(Vector3f(1.0f, 0.0f, 0.0f), 0.5f) // Matériau
    );

    // Test d'intersection
    float t = 0.0f;
    if (quad.is_hit(ray, t)) {
        std::cout << "Intersection trouvée à t = " << t << std::endl;
    } else {
        std::cout << "Aucune intersection trouvée." << std::endl;
    }

    // Rayon qui ne intersecte pas (parallèle)
    Ray3f ray_parallel(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, 1.0f, 0.0f));

    if (quad.is_hit(ray_parallel, t)) {
        std::cout << "Intersection trouvée (cas parallèle) à t = " << t << std::endl;
    } else {
        std::cout << "Aucune intersection trouvée (cas parallèle)." << std::endl;
    }
}




