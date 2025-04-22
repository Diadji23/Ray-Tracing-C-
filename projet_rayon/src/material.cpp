#include "material.hpp"
#include <algorithm>
#include <iostream>


//constructeur par defaut 
Material::Material()
        : ka_(0.0f, 0.0f, 0.0f), kd_(0.0f, 0.0f, 0.0f), ks_(0.0f, 0.0f, 0.0f), shininess_(0.0f) {}



// Constructeur avec paramètres
Material::Material(const Vector3f& ka, const Vector3f& kd, const Vector3f& ks, float shininess)
    : ka_(ka), kd_(kd), ks_(ks), shininess_(shininess) {}
 


float Material::get_shininess() const { return shininess_; }



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