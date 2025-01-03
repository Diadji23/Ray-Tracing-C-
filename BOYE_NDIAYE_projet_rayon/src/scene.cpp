#include "scene.hpp"


/*
*@brief constructeur par défaut 
*/
Scene::Scene()
    : camera_(), source_(Ray3f(Vector3f(0.0f, 10.0f, -10.0f), Vector3f(0.0f, -1.0f, 1.0f))) {}


/**
 * @brief Ajoute un objet à la scène.
*/
void Scene::add_object(Shape* shape) {
    objects_.push_back(shape);
}

/**
 * @brief Retourne la source lumineuse.
 */
const Ray3f& Scene::get_source() const {
    return source_;
}

/**
 * @brief Retourne les objets de la scène.
 */
const std::vector<Shape*>& Scene::get_objects() const {
    return objects_;
}


/**
 * @brief Définit la caméra pour la scène.
 */
void Scene::set_camera(const Camera& cam) {
    camera_ = cam;
}


/**
 * @brief Retourne la caméra utilisée dans la scène.
 */
const Camera& Scene::get_camera() const {
    return camera_;
}


// methode qui ajoute une sphere , un cube et les murs de la boite
    /*
    *@brief definit la taille de la grille/image ainsi que le nom du fichier ou on sauve l image
    *
    */


int main(){
    return 0 ; 
}