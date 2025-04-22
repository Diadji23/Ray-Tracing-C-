#ifndef MATERIAL_HPP 
#define MATERIAL_HPP 


#include "vector3f.hpp"

/**
 * @class Material
 * @brief Représente les propriétés d'un matériau dans un espace 3D.
 * 
 * Un matériau est défini par une couleur (vecteur RGB) et une propriété
 * de brillance (entre 0 et 1) pour les réflexions.
 */

class Material {
    private : 
        Vector3f ka_; // Coefficient de réflexion ambiante
        Vector3f kd_; // Coefficient de réflexion diffuse
        Vector3f ks_; // Coefficient de réflexion spéculaire
        //Vector3f color_ ; //couleur du materiau
        float  shininess_ ; // brillance du materiau (entre 0 et 1 )
    public : 
        /**
        * @brief Constructeur par défaut.
        * 
        * Initialise un matériau noir (RGB = (0, 0, 0)) avec une brillance nulle.
        */
        Material() ;

        /**
        * @brief Constructeur avec paramètres.
        * 
        * @param color Couleur du matériau (vecteur RGB).
        * @param shininess Brillance du matériau (doit être entre 0 et 1).
        */
        Material(const Vector3f& ka, const Vector3f& kd, const Vector3f& ks, float shininess) ;  

        
        /*
        *@brief Accede à la couleur du materiau 
        *@return Vector3f la couleur du materiau 
        */
        Vector3f get_color() const ; 

        /**
        * @brief Définit la couleur du matériau.
        * @param color La nouvelle couleur (vecteur RGB).
        */
        void set_color(const Vector3f& color)  ; 
    
    
        /**
        * @brief Accède à la brillance du matériau.
        * @return float La brillance (entre 0 et 1).
        */
        float get_shininess() const ;


        /**
        * @brief Définit la brillance du matériau.
        * @param shininess La nouvelle brillance (doit être entre 0 et 1).
        */
        void set_shininess(float shininess);

        //nouveau 
        /** 
        *@brief retourne le coef ambiant 
        */
        Vector3f get_ambient() const ;

        /** 
        * @brief retourne le coef diffuse  
        */ 
        Vector3f get_diffuse() const  ;

        /**
         * @brief met en place le coef ambiant 
         */
        void set_ambient(const Vector3f& ka) ; 

        /**
         * @brief retourne le coef spéculaire 
         */
        Vector3f get_specular() const ; 

        
        void set_specular( const Vector3f& ks) ; 
         
        void set_diffuse( const Vector3f& kd) ; 
        
}; 




#endif 