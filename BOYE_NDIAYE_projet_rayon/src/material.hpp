#ifdef MATERIAL_HPP 
#define MATERIAL_HPP 

/*
*@class 
**@brief 
*
*/

class Material {
    private : 
        vector3f color ; // vecteur (r , g , b)
        float  shininess_ ; 
    public : 
        Material() ;
        Material( const Vector3f color , float shininess) ;  

        ~Material() ; 

        //d autres methodes si necessaire 
        

}; 




#endif 