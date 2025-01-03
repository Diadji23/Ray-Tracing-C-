#ifndef SCENE_HPP
#define SCENE_HPP 
#include <vector>
#include <string>
#include "ray3f.hpp"
#include "vector3f.hpp"
#include "cube_quad.hpp"
#include "camera.hpp"
#include "material.hpp"







/**@class Scene
 * @brief represente une scene avec une caméra , des objets , et une source 
 * elle gere tous les éléments nécessaires pour produire une image
 * en utilisant l'algorithme de tracé de rayon
 */

class Scene
{
private:
    Camera camera_ ; 
    std::vector<Shape*> objects_ ;
    Ray3f source_ ; 

public:
    /*
    *@brief constructeur 
    * Initialse la scene vide avec une lumière par defaut 
    */
    Scene();
    // getters , setters

     /**
     * @brief Ajoute un objet à la scène.
     * @param shape Pointeur vers un objet dérivé de Shape.
     */
    void add_object(Shape* shape);



    /*
    *@brief ajoute une source de lumière sur la scene
    */
    void set_source(const Ray3f& source ); 



    /**
     * @brief Retourne la source lumineuse de la scène.
     * @return const Ray3f& La source lumineuse.
     */
    const Ray3f& get_source() const ; 

    /**
     * @brief Retourne les objets de la scène.
     * @return const std::vector<Shape*>& Liste des objets de la scène.
     */
    const std::vector<shape*>& get_object() ; 

    const Camera& get_camera(const Camera& cam) const; 
    
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
}  
#endif 