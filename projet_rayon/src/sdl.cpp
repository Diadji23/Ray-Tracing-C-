#include "sdl.hpp"
#include <iostream>
//contructeur
Sdl::Sdl(int width, int height, const std::string& title)
    : width_(width), height_(height), window_(nullptr), renderer_(nullptr) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Erreur d'initialisation de SDL: " << SDL_GetError() << std::endl;
        throw std::runtime_error("Impossible d'initialiser SDL");
    }

    window_ = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width_, height_, SDL_WINDOW_SHOWN);
    if (!window_) {
        std::cerr << "Erreur lors de la création de la fenêtre SDL: " << SDL_GetError() << std::endl;
        SDL_Quit();
        throw std::runtime_error("Impossible de créer la fenêtre SDL");
    }

    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer_) {
        std::cerr << "Erreur lors de la création du renderer SDL: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window_);
        SDL_Quit();
        throw std::runtime_error("Impossible de créer le renderer SDL");
    }
}

//destructeur 

Sdl::~Sdl() {
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    SDL_Quit();
}


//rendu
void Sdl::render(const std::vector<std::vector<Vector3f>>& image) {
    SDL_RenderClear(renderer_);

    for (int y = 0; y < height_; ++y) {
        for (int x = 0; x < width_; ++x) {
            const Vector3f& color = image[y][x];
            SDL_SetRenderDrawColor(renderer_,
                                   static_cast<Uint8>(color.getX() * 255),
                                   static_cast<Uint8>(color.getY() * 255),
                                   static_cast<Uint8>(color.getZ() * 255),
                                   255);
            SDL_RenderDrawPoint(renderer_, x, height_ - y - 1);
        }
    }

    SDL_RenderPresent(renderer_);
}

// gestion des evenements 

bool Sdl::handle_events() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return false;
        }
    }
    return true;
}

