#include "scene.hpp"
#include <iostream>



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
void Scene::add_light(const Light& light) {
    lights_.push_back(light);
}


/**
 * @brief Retourne la source lumineuse.
 */
const Ray3f& Scene::get_source() const {
    return source_;
}


/**
 * @brief Définit la caméra pour la scène.
 */
void Scene::set_camera(const Camera& cam) {
    camera_ = cam;
}


/**
 * @brief Définit la source pour la scène.
 */
void Scene::set_source( const Ray3f& source ) {
    source_ = source ;
}


/**
 * @brief Retourne la caméra utilisée dans la scène.
 */
const Camera& Scene::get_camera() const {
    return camera_;
}



/*void Scene::render(int width, int height, const std::string& outputFile) const {
    // Ouvre le fichier de sortie
    std::ofstream out(outputFile);
    if (!out) {
        throw std::runtime_error("Impossible de créer le fichier de sortie.");
    }

    // Format PPM
    out << "P3\n" << width << " " << height << "\n255\n";

    for (int y = height - 1; y >= 0; --y) {
        for (int x = 0; x < width; ++x) {
            // Génère un rayon pour ce pixel
            Ray3f ray = camera_.generate_ray(x, y, width, height);

            // Détermine la couleur associée
            Vector3f color(0.0f, 0.0f, 0.0f);
            Shape* hit_object = nullptr;

            float closest_t = 1e6;
            for (const auto& obj : objects_) {
                float t;
                if (obj->isHit(ray, t,intersection_point) && t < closest_t) {
                    closest_t = t;
                    hit_object = obj;
                }
            }

            if (hit_object) {
                Material material = hit_object->get_material();
                color = material.get_color();
            }

            // Écrit les valeurs de couleur
            int r = static_cast<int>(255.99f * color.getX());
            int g = static_cast<int>(255.99f * color.getY());
            int b = static_cast<int>(255.99f * color.getZ());

            out << r << " " << g << " " << b << "\n";
        }
    }

    out.close();
}

*/


void Scene::render_to_image(int width, int height, std::vector<std::vector<Vector3f>>& image) const {
    // Parcours des pixels
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Génération d'un rayon pour ce pixel
            Ray3f ray = camera_.generate_ray(x, y, width, height);

            // Initialisation de la couleur (noir par défaut)
            Vector3f color(0.0f, 0.0f, 0.0f);
            Shape* hit_object = nullptr;

            // Trouver l'intersection la plus proche
            float closest_t = 1e6; // Distance initiale très grande
            Vector3f intersection_point, normal;

            for (const auto& obj : objects_) {
                float t;
                Vector3f temp_intersection, temp_normal;

                // Test d'intersection avec l'objet
                if (obj->isHit(ray, t, temp_intersection, temp_normal) && t < closest_t) {
                    closest_t = t;
                    intersection_point = temp_intersection;
                    normal = temp_normal;
                    hit_object = obj;
                }
            }

            // Si un objet est intersecté
            if (hit_object) {
                Material material = hit_object->get_material();

                // Composantes d'éclairage
                Vector3f ambient_color(0.0f, 0.0f, 0.0f);
                Vector3f diffuse_color(0.0f, 0.0f, 0.0f);
                Vector3f specular_color(0.0f, 0.0f, 0.0f);

                // Calcul des contributions lumineuses
                for (const auto& light : lights_) {
                    Vector3f L = (light.position - intersection_point).normalize(); // Direction de la lumière
                    Vector3f V = (camera_.get_position() - intersection_point).normalize(); // Direction vers la caméra

                    // Composante ambiante
                    ambient_color = ambient_color +  light.ambient * material.get_ambient() ;

                    // Composante diffuse (Lambert)
                    float diff = std::max(normal.dot(L), 0.0f);
                    diffuse_color= diffuse_color + material.get_diffuse() * light.diffuse * diff;

                    // Composante spéculaire (Phong)
                    Vector3f R = (2.0f * normal.dot(L) * normal - L).normalize(); // Réflexion
                    float spec = std::pow(std::max(R.dot(V), 0.0f), material.get_shininess());
                    specular_color = specular_color + material.get_specular() * light.specular * spec;
                }

                // Additionner les composantes pour obtenir la couleur finale
                color = ambient_color + diffuse_color + specular_color;

                // Limiter les valeurs entre 0 et 1
                color = color.clamp(0.0f, 1.0f);
            }

            // Affecter la couleur au pixel correspondant
            image[y][x] = color;
        }
    }
}
