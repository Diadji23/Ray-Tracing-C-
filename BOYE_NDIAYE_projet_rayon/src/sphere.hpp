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
};

#endif