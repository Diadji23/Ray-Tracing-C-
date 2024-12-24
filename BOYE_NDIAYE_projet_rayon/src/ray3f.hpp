#ifdef RAY3F_HPP
#define RAY3F_HPP
#include "vector3f.hpp"


/**
 * @class Ray3f
 * @brief 
 * 
 */

class Ray3f {
    private: 
        Vector3f origin_ ; 
        Vector3f direction_ ; 

    public : 
        //constructeur et destructeur
        Ray3f(const vector3f& origin , const vector3f& direction) ;
        ~Ray3f() ; 

        //getters  d autres methodes ?        
} ;
#endif 