#ifndef CAMERA_H
#define CAMERA_H

#include "vector3f.hpp"
#include "ray3f.hpp"
/**
 * @class Camera
 * @brief Représente une caméra dans la scène.
 * 
 * La caméra définit l'origine des rayons et la direction dans laquelle
 * les rayons sont projetés.
 */

class Camera {
private:
    Vector3f position_; //position de la caméra
    Vector3f direction_; //direction 
public:

    /**
     * @brief Constructeur par défaut.
     */
    Camera();

    /**
     * @brief Constructeur de la classe Camera.
     * 
     * @param position Position de la caméra.
     * @param direction Direction dans laquelle la caméra regarde.
     */
    Camera(const Vector3f& position, const Vector3f& direction); 

    /**
     * @brief Définit la position de la caméra.
     */
    void set_position(const Vector3f& position); 

    /**
     * @brief Définit la direction de la caméra.
     */
    void set_direction(const Vector3f& direction); 


    /**
     * @brief Génère un rayon pour un pixel donné.
     * @param x Position horizontale du pixel.
     * @param y Position verticale du pixel.
     * @param width Largeur de l'image en pixels.
     * @param height Hauteur de l'image en pixels.
     * @return Ray3f Le rayon généré.
     */
    Ray3f generate_ray(int x, int y, int width, int height) const;

    void set_camera_angle(float yaw, float pitch) ;
};

#endif