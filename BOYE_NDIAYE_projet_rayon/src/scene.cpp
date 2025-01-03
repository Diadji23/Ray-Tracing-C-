#include "scene.hpp"


// methode qui ajoute une sphere , un cube et les murs de la boite
    /*
    *@brief definit la taille de la grille/image ainsi que le nom du fichier ou on sauve l image
    *
    */
void scene::render(int width , int height , const std::string& outputFile) const {
    // Grille
    std::vector<std::vector<vector3f>> pixels(height , std::vector<Vector3f>(width)) ; 

    for( int y = 0 ; y < height ; y++){
        for(int x  = 0 ; x < width ; x ++ ) {
            float u = ( x + 0.5f ) / width * 2.0f - 1.0f; 

            float v = (  y + 0.5f ) / height * 2.0f - 1.0f ; 

            Ray3f ray = camera-> get_ray(u , v) ; 

            pixels[y][x] = calcul_couleur(ray) ; 

        }
    }

save_image(pixels , outpuTFile) ; 

}