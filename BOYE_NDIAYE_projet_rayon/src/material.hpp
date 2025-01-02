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
        float  shinyness_ ; // entre 0 et 1 
    public : 
        //constructeur par defaut 
        Material() ;

        //constructeur a apratir de la couleur et la luminnoisté 
        Material( const Vector3f color , float shininess) ;  

        
        ~Material() ; 

        //d autres methodes si necessaire 
        
}; 




#endif 