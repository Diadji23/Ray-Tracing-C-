#ifndef SHAPE_H
#define SHAPE_H

#include "Vector3f.hpp"
#include "Ray3f.hpp"
#include "materiel.hpp"

/**
 * @class Shape
 * @brief Classe abstraite représentant une forme géométrique.
 * 
 * Les classes dérivées doivent implémenter les méthodes pour détecter les
 * intersections et gérer les propriétés des formes spécifiques.
 */

class Shape {
private:
    Materiel matter; //matériau de la forme

public:
    /**
     * @brief Teste si un rayon intersecte la forme.
     * 
     * @param ray Le rayon à tester.
     * @param hitPoint Le point d'intersection, si trouvé.
     * @return `true` si une intersection est trouvée, sinon `false`.
     */

    virtual isHit(const Ray3f& ray) const ;

    /**
     * @brief calcule le rayon réfléchie de ray.
     * 
     * @param ray Le rayon dont on calcule le rayon réfléchie.
     * @return le rayon réfléchie
     */
    virtual Vector3f reflect(const Ray3f& ray) const;
    virtual ~Shape() {}
};

#endif