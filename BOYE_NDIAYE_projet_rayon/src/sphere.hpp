#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"
/**
 * @class Sphere
 * @brief Représente une sphère dans la scène.
 * 
 * Une sphère est définie par son centre, son rayon et son matériau.
 */
class Sphere : public Shape {
private:
    Vector3f origin; //origine de la sphère
    float radius; //rayon

public:
    /**
     * @brief Constructeur de la classe Sphere.
     * 
     * @param center Le centre de la sphère.
     * @param radius Le rayon de la sphère.
     * @param material Le matériau de la sphère.
     */
    Sphere(const Vector3f& center, float radius, const Material& material);

    /**
     * @brief Teste si un rayon intersecte la sphère.
     * 
     * @param ray Le rayon à tester.
     * @param hitPoint Le point d'intersection, si trouvé.
     * @return `true` si une intersection est trouvée, sinon `false`.
     */
    bool isHit(const Ray3f& ray, float& t) const override;
    
    /**
     * @brief Teste si un rayon intersecte la sphère.
     * 
     * @param ray Le rayon à tester.
     * @param hitPoint Le point d'intersection, si trouvé.
     * @return `true` si une intersection est trouvée, sinon `false`.
     */
    Vector3f reflect(const Ray3f& ray, const Vector3f& point) const override;
};

#endif