# Projet de lancer de rayons (Ray Tracing) en C++

##  Objectif

Ce projet implémente un moteur simple de **lancer de rayons** permettant de générer des images 3D réalistes en simulant le comportement de la lumière dans une scène composée de sphères, de cubes et de sources lumineuses.

## Structure du projet

- `main.cpp` : Point d'entrée du programme.
- `scene.cpp` / `scene.hpp` : Contient la classe `Scene` qui gère les objets, les lumières et le rendu.
- `camera.cpp` / `camera.hpp` : Définition de la caméra et génération des rayons.
- `vector3f.cpp` / `vector3f.hpp` : Vecteurs 3D et opérations associées.
- `material.cpp` / `material.hpp` : Décrit les propriétés physiques d’un matériau (couleur, brillance, etc.).
- `sphere.cpp` / `sphere.hpp` : Représentation géométrique d’une sphère.
- `cube_quad.cpp` / `cube_quad.hpp` : Définition d’un cube (via des quads).
- `ray3f.cpp` / `ray3f.hpp` : Classe `Ray3f` représentant un rayon 3D.
- `sdl.cpp` / `sdl.hpp` : Utilisation de SDL2 pour afficher l’image générée.

##  Compilation

### Prérequis

Assurez-vous d’avoir :

- `g++` (ou tout autre compilateur C++)
- `SDL2` installé (`libsdl2-dev`)
- `pkg-config` pour récupérer les flags de compilation SDL2

### Compilation

```bash
g++ -g -Wall -Wextra -o prog *.cpp $(pkg-config --cflags --libs sdl2)

./prog


## Concepts physiques utilisés : Le moteur utilise le modèle d’éclairage de Phong -> https://fr.wikipedia.org/wiki/Ombrage_de_Phong

## Resultat SDL -> Voir projet_rayon/img

## Projet réalisé dans un cadre académique ( Cours C++ ENSIIE)


