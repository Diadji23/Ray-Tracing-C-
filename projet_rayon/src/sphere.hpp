#ifndef SPHERE_H
#define SPHERE_H

#include "shape.hpp"
/**
 * @class Sphere
 * @brief Représente une sphère dans la scène.
 * 
 * Une sphère est définie par son centre, son rayon et son matériau.
 */
class Sphere : public Shape {
private:
    Vector3f origin_; //origine de la sphère
    float radius_; //rayon
    Material material_ ;
public:
    /**
     * @brief Constructeur de la classe Sphere.
     * 
     * @param center Le centre de la sphère.
     * @param radius Le rayon de la sphère.
     * @param material Le matériau de la sphère.
     */
    Sphere(const Vector3f& origin, float radius, const Material& material) ;

    bool isHit(const Ray3f& ray, float& t, Vector3f& intersection_point, Vector3f& normal) const override; 

    Material get_material() const override;


    //Vector3f reflect(const Ray3f& ray, const Vector3f& point) const override ; 


    Vector3f get_origin() const override ;
    Vector3f get_height() const override ;
    Vector3f get_width() const override ; 
    
};

#endif