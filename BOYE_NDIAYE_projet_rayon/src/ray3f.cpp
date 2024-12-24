#include "ray3f.hpp"


// constructeur de la classe 
Ray3f(const vector3f& origin , const vector3f& direction){

    origin_ = origin ; 
    direction_ = direction ; 

}



~Ray3f() ; 

//Getters et methodes nécessaires 