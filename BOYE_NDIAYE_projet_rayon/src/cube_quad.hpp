#ifndef CUBE_QUAD_HPP
#define CUBE_QUAD_HPP


class Cub_quad : public Shape{
    public : 
        Vector3f width_ ; 
        Vector3f height_ ; 
        Vector3f origin_ ;
    private : 
        //constructeurs 
        Cub_quad(Vector3f width , vector3f height ) ; 

        ~Cub_quad() ; 
        /*
        *@brief vérifie si un rayon intersecte un quadrilatère défini dans un plan
        @param ray Le rayon à tester 
        @param t Distance à l'intersection , si elle existe
        @ true si intersection , false sinon
        */
        bool is_hit(const Ray3f& ray , float& t ) const override ; 

        
    

} ; 

#endif ; 