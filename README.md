#  Ray Tracing Renderer en C++

Un moteur de rendu 3D développé en C++ implémentant l’algorithme de **tracé de rayons (ray tracing)** pour générer des images réalistes à partir d’une scène virtuelle composée d’objets géométriques, d’une caméra, et d’une source lumineuse.

## Fonctionnalités

- Création d’une scène avec :
  - Une caméra positionnée dynamiquement
  - Une source de lumière directionnelle
  - Des objets géométriques (sphères, quadrilatères)
- Algorithme de tracé de rayons :
  - Calculs d’intersections rayon-objet
  - Gestion des ombres et de l’éclairage (diffus, ambiant, spéculaire)
  - Réflexions simples
- Affichage de l’image générée avec **SDL2**
- Sauvegarde possible au format **PPM**

## Structure du projet

##  Compilation

Assurez-vous d’avoir installé **SDL2**.

### Linux / WSL

```bash
g++ -Wall -o raytracer \
    src/*.cpp -lSDL2
./raytracer

## Objectifs

--> Comprendre le fonctionnement du ray tracing

--> Maîtriser les mathématiques 3D (vecteurs, produits scalaires, intersections)

--> Gérer une architecture orientée objet en C++

--> Afficher des images en temps réel avec SDL

## Resultat SDL -> Voir projet_rayon/img

## Projet réalisé dans un cadre académique ( Cours C++ ENSIIE)

