#ifndef SCENE_HPP
#define SCENE_HPP 

#include <vector>
#include <string>
#include <fstream>


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

    //const std::vector<Shape>& get_objects() const ; 

    /*
    *@brief ajoute une source de lumière sur la scene
    */
    void set_source(const Ray3f& source ); 

    /**
    * @brief Définit la caméra pour la scène.
    */
    void set_camera(const Camera& cam) ;

    /**
     * @brief Retourne la source lumineuse de la scène.
     * @return const Ray3f& La source lumineuse.
     */
    const Ray3f& get_source() const ; 

    
    /**
    * @brief Retourne la caméra utilisée dans la scène.
    */
    const Camera& get_camera() const ;

    /**
     * @brief Retourne les objets de la scène.
     * @return const std::vector<Shape*>& Liste des objets de la scène.
     */
    const std::vector<Shape*>& get_object() ; 

    const Camera& get_camera(const Camera& cam) const; 
    
    

    // methodes autres 

public:
    // methode qui ajoute une sphere , un cube et les murs de la boite
    /*
    *@brief definit la taille de la grille/image ainsi que le nom du fichier ou on sauve l image
    *
    */
   void render(int width , int height , const std::string& outputFile) const ; 


   /**
 * @brief Génère une matrice de couleurs représentant l'image.
 * 
 * @param width Largeur de l'image.
 * @param height Hauteur de l'image.
 * @param image Matrice de couleurs à remplir.
 */
    void render_to_image(int width, int height, std::vector<std::vector<Vector3f>>& image) const;

    Vector3f compute_shading(const Vector3f& point, const Vector3f& normal, const Material& material, const Ray3f& ray) const ;
private : 
    /**
     * @brief Vérifie si un point est dans l'ombre.
     * @param point Point à tester.
     * @return True si le point est dans l'ombre, sinon false.
     */
    bool is_in_shadow(const Vector3f& point) const;

}  ;
#endif 