#ifndef SHAPE_H
#define SHAPE_H

#include "vector3f.hpp"
#include "ray3f.hpp"
#include "material.hpp"

/**
 * @class Shape
 * @brief Classe abstraite représentant une forme géométrique.
 * 
 * Les classes dérivées doivent implémenter les méthodes pour détecter les
 * intersections et gérer les propriétés des formes spécifiques.
 */


class Shape {
public:

    /**
     * @brief Teste si un rayon6 intersecte la forme.
     * 
     * @param ray Le rayon à tester.
     * @param hitPoint Le point d'intersection, si trouvé.
     * @return `true` si une intersection est trouvée, sinon `false`.
     */

    virtual bool  isHit(const Ray3f& ray, float& t, Vector3f& intersection_point, Vector3f& normal) const = 0;

    /**
     * @brief Retourne le matériau associé à la forme.
     * @return Material Le matériau de la forme.
     */
    virtual Material get_material() const = 0;

    /**
     * @brief calcule le rayon réfléchie de ray.
     * 
     * @param ray Le rayon dont on calcule le rayon réfléchie.
     * @return le rayon réfléchie
     */
    //virtual Vector3f reflect(const Ray3f& ray, const Vector3f& point) const = 0; 
    virtual Vector3f get_origin() const = 0;
    virtual Vector3f get_height() const= 0;
    
    virtual  Vector3f get_width() const = 0 ;

    virtual ~Shape()= default ; 
};


#endif

