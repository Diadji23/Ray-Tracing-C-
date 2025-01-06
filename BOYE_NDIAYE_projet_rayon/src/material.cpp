#include "material.hpp"
#include <algorithm>
#include <iostream>


//Material::Material() : color_(0.0f, 0.0f, 0.0f), shininess_(0.0f) {}
Material::Material()
        : ka_(0.0f, 0.0f, 0.0f), kd_(0.0f, 0.0f, 0.0f), ks_(0.0f, 0.0f, 0.0f), shininess_(0.0f) {}

//Material::Material(const Vector3f& color, float shininess)
   // : color_(color), shininess_(std::clamp(shininess, 0.0f, 1.0f)){}



//methodes 


//Vector3f Material::get_color() const { return color_; }


//void Material::set_color(const Vector3f& color) { color_ = color; }


float Material::get_shininess() const { return shininess_; }

/**
     * @brief Définit la brillance du matériau.
     * @param shininess La nouvelle brillance (doit être entre 0 et 1).
 */
/**
 * @brief Définit la brillance du matériau.
 */
void Material::set_shininess(float shininess) {
    shininess_ = std::clamp(shininess, 0.0f, 1.0f); // Brillance limitée entre 0 et 1
}

Vector3f Material::get_ambient() const {
     return ka_ ; 
     }

void Material::set_ambient(const Vector3f& ka) { ka_ = ka; }

Vector3f Material::get_diffuse() const { return kd_; }

void Material::set_diffuse(const Vector3f& kd) { kd_ = kd; }

Vector3f Material::get_specular() const { return ks_; }

void Material::set_specular(const Vector3f& ks) { ks_ = ks; }