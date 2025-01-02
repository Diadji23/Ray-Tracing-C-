#ifndef RAY3F_HPP
#define RAY3F_HPP
#include <sstream> 

#include <string>
#include "vector3f.hpp"


/**
 * @class Ray3f
 * @brief  représente un rayon dans un espace 3D 
 * un rayon est défini par une origine et une direction 
 * on normalise la direction pour garantir la precision des calculs
 * 
 */

class Ray3f {
    private: 
        Vector3f origin_ ; 
        Vector3f direction_ ; 

    public : 
        /**
     *   @brief Constructeur par défaut.
        *   
        * Initialise un rayon avec une origine (0, 0, 0) et une direction (1, 0, 0).
        */
       Ray3f()  ; 


        /**
        * @brief Constructeur avec une origine et une direction.
        * 
        * La direction est automatiquement normalisée.
        * 
        * @param origin Origine du rayon.
        * @param direction Direction du rayon (sera normalisée).
        */
        Ray3f(const Vector3f& origin , const Vector3f& direction) ;

        ~Ray3f() ; 

        //getters  d autres methodes ?   
        /**
     * @brief Retourne un point à une distance donnée le long du rayon.
     * 
     * @param t Distance paramétrique le long du rayon.
     * @return Vector3f Le point correspondant sur le rayon.
     */
    Vector3f point_at(float t) const ;

    
} ;


#endif 