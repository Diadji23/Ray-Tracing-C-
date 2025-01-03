#ifndef SCENE_HPP
#define SCENE_HPP 
#include <vector>
#include <string>
#include "Camera.hpp"
#include "Material.hpp"







/**@class Scene
 * @brief represente une scene avec une caméra , des objets , et une source 
 * elle gere tous les éléments nécessaires pour produire une image
 * en utilisant l'algorithme de tracé de rayon
 */

class Scene
{
private:
    camera camera_ ; 
    std::vector<shape> object_ ;
    Ray3f source_ ; 

public:
    /*
    *@brief constructeur 
    * Initialse la scene vide avec une lumière par defaut 
    */
    Scene();
    // getters , setters

    /*
    *ajoute une source de lumière sur la scene
    */
    void set_source(const Ray3f& source ); 

    // permet d acceder a la source 
    source& get_source() const ; 

    // acceder à l ensemble des objets de la scene
    std::vector<shape>& get_object() ; 

    camera& get_camera(const camera& cam) ; 
    
    //cette methode met en place une caméra pour notre scene
    void set_camera(const camera& cam ); 

    // methodes autres 

public:
    // methode qui ajoute une sphere , un cube et les murs de la boite
    /*
    *@brief definit la taille de la grille/image ainsi que le nom du fichier ou on sauve l image
    *
    */
   void render(int width , int height , const std::string& outputFile) const ; 

private : 
    /**
     * @brief suit un rayon dans la scene pour calculer sa couleur
     * @param ray , le rayon à tracer 
     * @return La couleur calculée au point d'intersection
     */

    Vector3f calcul_couleur(const Ray3f& ray) const {
        Vector3f color(0.0f , 0.0f , 0.Of) ; 

        float closest = std::numeric_limits<float>::max() ;

        for ( const auto& obj : objects ) {
            float t ; 
            if(obj->is_hit(ray, t ) &&  t < closest) {
                closest = t ; 
                Vector3f hitPoint = ray.point_at(t) ;

                color = compute_lighting(hitPoint)
            }
        }
    }
    
   
}

#endif 