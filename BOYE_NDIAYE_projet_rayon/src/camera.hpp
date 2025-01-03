#ifndef CAMERA_H
#define CAMERA_H

#include "vector3f.hpp"

<<<<<<< HEAD
/**
 * @class Camera
 * @brief Représente une caméra dans la scène.
 * 
 * La caméra définit l'origine des rayons et la direction dans laquelle
 * les rayons sont projetés.
 */

class Camera {
private:
    Vector3f position; //position de la caméra
    Vector3f direction; //direction
public:
    /**
     * @brief Constructeur de la classe Camera.
     * 
     * @param position Position de la caméra.
     * @param direction Direction dans laquelle la caméra regarde.
     */
=======
class Camera {
public:
    Vector3f position_;
    Vector3f direction_;
private :
    Camera() ; 
>>>>>>> bbce886164e2b057a433b81debe33fefc9e5e6ab
    Camera(const Vector3f& position, const Vector3f& direction);
    //
  

};

#endif