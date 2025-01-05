#include <iostream>
#include "sdl.hpp"

#include "scene.hpp"
#include "cube_quad.hpp"

#include "material.hpp"
#include "sphere.hpp"



int main(){
    //dimensions de la fenetre 
    const int width = 800 ; 
    const int height = 600 ; 

    //on crée l'instance SDL

    Sdl sdl(width , height , " Rendered Scene") ; 

    
    Scene scene ; 

    // Dimensions de la boîte
    float box_size = 10.0f ; 

    //configurer la caméra

    Camera camera(Vector3f(0.0f ,1.0f , 5.0f), Vector3f(0.0f, 0.0f , -1.0f)) ;
    //angle de la caméra 
    camera.set_camera_angle(45.0f, -15.0f) ;
    scene.set_camera(camera) ; 


    // source lumineuse au dessus de la boite*
    Ray3f light_source(Vector3f(0.0f, box_size, 0.0f), Vector3f(0.0f, -1.0f, 0.0f));
    scene.set_source(light_source);


    // Matériaux pour les objets
    Material red(Vector3f(1.0f, 0.0f, 0.0f), 0.5f);
    Material green(Vector3f(0.0f, 1.0f, 0.0f), 0.5f);
    Material blue(Vector3f(0.0f, 0.0f, 1.0f), 0.5f);
    Material gray(Vector3f(0.5f, 0.5f, 0.5f), 0.5f);
    Material white(Vector3f(1.0f, 1.0f, 1.0f), 0.5f);

    // Quadrilatères pour la boîte
    Cub_quad left(Vector3f(-box_size, -box_size, -box_size), Vector3f(0.0f, 2 * box_size, 0.0f), Vector3f(0.0f, 0.0f, 2 * box_size), gray);
    Cub_quad right(Vector3f(box_size, -box_size, -box_size), Vector3f(0.0f, 2 * box_size, 0.0f), Vector3f(0.0f, 0.0f, 2 * box_size), gray);
    Cub_quad bottom(Vector3f(-box_size, -box_size, -box_size), Vector3f(2 * box_size, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 2 * box_size), white);
    Cub_quad top(Vector3f(-box_size, box_size, -box_size), Vector3f(2 * box_size, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 2 * box_size), white);
    Cub_quad back(Vector3f(-box_size, -box_size, box_size), Vector3f(2 * box_size, 0.0f, 0.0f), Vector3f(0.0f, 2 * box_size, 0.0f), gray);


    // Ajouter les quadrilatères à la scène
    scene.add_object(&left);
    scene.add_object(&right);
    scene.add_object(&bottom);
    scene.add_object(&top);
    scene.add_object(&back) ; 



    // on ajoute ici une sphere
    Sphere sphere(Vector3f(0.0f, -5.0f, 0.0f), 3.0f, Material(Vector3f(1.0f, 0.0f, 0.0f), 0.7f));
    scene.add_object(&sphere);

  // Générer l'image (matrice de couleurs)
    std::vector<std::vector<Vector3f>> image(height, std::vector<Vector3f>(width));
    scene.render_to_image(width, height, image);

  //afficher l'image avec sdl 

  while( sdl.handle_events()){
    sdl.render(image) ; 
  }

    return 0 ; 

}