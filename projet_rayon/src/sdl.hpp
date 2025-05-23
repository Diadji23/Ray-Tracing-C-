#ifndef SDL_HPP
#define SDL_HPP

#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include "vector3f.hpp"

/**
 * @class Sdl
 * @brief Gère l'affichage d'une image avec SDL.
 */
class Sdl {
private:
       // Renderer SDL.
    int width_;                
    int height_;  
    SDL_Window* window_;      
    SDL_Renderer* renderer_;           

public:
    /**
     * @brief Constructeur de la classe Sdl.
     * 
     * @param width Largeur de la fenêtre.
     * @param height Hauteur de la fenêtre.
     * @param title Titre de la fenêtre.
     */
    Sdl(int width, int height, const std::string& title);

    /**
     * @brief Destructeur de la classe Sdl.
     * Nettoie les ressources SDL.
     */
    ~Sdl();

    /**
     * @brief Affiche une image en utilisant SDL.
     * 
     * @param image Matrice de couleurs représentant l'image à afficher.
     */
    void render(const std::vector<std::vector<Vector3f>>& image);

    /**
     * @brief Gère la boucle d'événements SDL.
     * 
     * @return true si l'utilisateur continue, false s'il ferme la fenêtre.
     */
    bool handle_events();
};

#endif 
