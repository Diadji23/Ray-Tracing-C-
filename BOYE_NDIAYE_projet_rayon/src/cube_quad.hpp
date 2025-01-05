#ifndef CUBE_QUAD_HPP
#define CUBE_QUAD_HPP

#include "shape.hpp"
#include "vector3f.hpp"
#include "ray3f.hpp"
#include "material.hpp"



/*
*@class Cub_quad 
@brief Représente un quadrilatère dans un espace 3D
*/


class Cub_quad : public Shape{
    private :
        Vector3f origin_ ; // origine du quad (un coin )
        Vector3f width_ ; // largeur du quad 
        Vector3f height_ ; // longueur su quad 
        Material material_ ; // Materiau associé au quadrilatere
    public : 
         /**
     * @brief Constructeur de Cub_quad.
     * 
     * @param origin Origine (coin inférieur gauche) du quadrilatère.
     * @param width Largeur du quadrilatère.
     * @param height Hauteur du quadrilatère.
     * @param material Matériau du quadrilatère.
     */
        Cub_quad(const Vector3f& origin, const Vector3f& width ,const Vector3f&  height, const Material& material ) ; 

        /*
        *@brief vérifie si un rayon intersecte un quadrilatère défini dans un plan
        @param ray Le rayon à tester 
        @param t Distance à l'intersection , si elle existe
        @ true si intersection , false sinon
        */
        bool isHit(const Ray3f& ray , float& t ) const override ; 

        /**
        * @brief Retourne le matériau associé au quadrilatère.
        * 
        * @return Material Le matériau du quadrilatère.
        */ 
        Material get_material() const override;

        Vector3f reflect(const Ray3f& ray, const Vector3f& point) const override ; 
         
} ;     

#endif 