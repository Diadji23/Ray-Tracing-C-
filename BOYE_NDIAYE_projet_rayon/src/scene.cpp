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
 
const std::vector<Shape>& Scene::get_objects() const {
    return objects_;
}

*/
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


// methode qui ajoute une sphere , un cube et les murs de la boite
    /*
    *@brief definit la taille de la grille/image ainsi que le nom du fichier ou on sauve l image
    *
    */

// essai rendu 


void Scene::render(int width, int height, const std::string& outputFile) const {
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
                if (obj->isHit(ray, t) && t < closest_t) {
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

void Scene::render_to_image(int width, int height, std::vector<std::vector<Vector3f>>& image) const {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Générer un rayon pour ce pixel
            Ray3f ray = camera_.generate_ray(x, y, width, height);

            // Couleur par défaut (noir)
            Vector3f color(0.0f, 0.0f, 0.0f);
            Shape* hit_object = nullptr;

            // Trouver l'intersection la plus proche
            float closest_t = 1e6;
            for (const auto& obj : objects_) {
                float t;
                if (obj->isHit(ray, t) && t < closest_t) {
                    closest_t = t;
                    hit_object = obj;
                }
            }

            // Déterminer la couleur
            if (hit_object) {
                Material material = hit_object->get_material();
                color = material.get_color();
            }

            // Remplir le pixel correspondant dans l'image
            image[y][x] = color;
        }
    }
}


