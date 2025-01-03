#include "material.hpp"
#include <algorithm>
#include <iostream>


Material::Material() : color_(0.0f, 0.0f, 0.0f), shininess_(0.0f) {}


Material::Material(const Vector3f& color, float shininess)
    : color_(color), shininess_(std::clamp(shininess, 0.0f, 1.0f)){}




//methodes 


Vector3f Material::get_color() const { return color_; }


void Material::set_color(const Vector3f& color) { color_ = color; }


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

void test_default_constructor() {
    Material material;
    std::cout << "Test constructeur par défaut:" << std::endl;
    std::cout << "Couleur : (" << material.get_color().x << ", " 
              << material.get_color().y << ", " << material.get_color().z << ")" << std::endl;
    std::cout << "Brillance : " << material.get_shininess() << std::endl << std::endl;
}


void test_param_constructor() {
    Vector3f color(0.5f, 0.2f, 0.8f);
    float shininess = 0.7f;
    Material material(color, shininess);

    std::cout << "Test constructeur avec paramètres:" << std::endl;
    std::cout << "Couleur : (" << material.get_color().x << ", " 
              << material.get_color().y << ", " << material.get_color().z << ")" << std::endl;
    std::cout << "Brillance : " << material.get_shininess() << std::endl << std::endl;
}


void test_setters() {
    Material material;
    material.set_color(Vector3f(1.0f, 0.0f, 0.0f));
    material.set_shininess(0.9f);

    std::cout << "Test des setters:" << std::endl;
    std::cout << "Couleur : (" << material.get_color().x << ", " 
              << material.get_color().y << ", " << material.get_color().z << ")" << std::endl;
    std::cout << "Brillance : " << material.get_shininess() << std::endl << std::endl;
}


