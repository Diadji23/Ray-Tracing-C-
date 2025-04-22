#include "camera.hpp"
#include <cmath>
// Fonction pour convertir les degrés en radians
inline float radians(float degrees) { 
    return degrees * static_cast<float>(M_PI) / 180.0f; }


//constructeur par défaut 
Camera::Camera()
    : position_(0.0f, 0.0f, 0.0f), direction_(0.0f, 0.0f, -1.0f), fov_(radians(60.0f)) {}


//constructeur valué 

Camera::Camera(const Vector3f& position, const Vector3f& direction)
    : position_(position), direction_(direction.normalize()) , fov_(radians(60.0f)){}  

//setters , getters 

void Camera::set_position(const Vector3f& position) {
    position_ = position;
}

void Camera::set_direction(const Vector3f& direction) {
    direction_ = direction.normalize();
}


void Camera::set_camera_angle(float yaw, float pitch)
 { 
    float yaw_radians = radians(yaw); 
    float pitch_radians = radians(pitch);
  // Calcul de la nouvelle direction en utilisant les angles
   
     direction_ = Vector3f( cos(yaw_radians) * cos(pitch_radians), sin(pitch_radians), sin(yaw_radians) * cos(pitch_radians) ).normalize();
}


//fonction qui génère des rayons 
Ray3f Camera::generate_ray(int x, int y, int width, int height) const {
    // Normalisation des coordonnées du pixel (x, y) entre -1 et 1
    float u = (2.0f * (x + 0.5f) / static_cast<float>(width)) - 1.0f;
    float v = (2.0f * (y + 0.5f) / static_cast<float>(height)) - 1.0f;

    float aspect_ratio = static_cast<float>(width) / static_cast<float>(height);

    // Ajuster pour le FOV
    float scale = std::tan(fov_ / 2.0f);
    u *= aspect_ratio * scale;
    v *= scale;

    
    // Système de coordonnées local de la caméra
    Vector3f right = direction_.cross(Vector3f(0.0f, 1.0f, 0.0f)).normalize(); // Axe X local
    Vector3f up = right.cross(direction_).normalize();

    // Direction du rayon (le plan d'image est centré devant la caméra)
    Vector3f ray_direction = (direction_ + right * u + up * v).normalize();

    // Retourne le rayon
    return Ray3f(position_, ray_direction);
}

void Camera::set_fov(float fov_degrees) {
    fov_ = radians(fov_degrees);
}



Vector3f Camera::get_position() const {
    return position_ ; 
};