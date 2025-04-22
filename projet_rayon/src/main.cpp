#include <iostream>
#include "sdl.hpp"

#include "scene.hpp"
#include "cube_quad.hpp"

#include "material.hpp"
#include "sphere.hpp"



int main(){
    //dimensions de la fenetre 
    const int width = 1500; 
    const int height = 1200 ; 

    //on crée l'instance SDL

    Sdl sdl(width , height , " Rendered Scene") ; 

    
    Scene scene ; 

    // Dimensions de la boîte
    float box_size = 10.0f ; 

    //on a positionné la cam en -3o  sur l'axe z
    Vector3f camera_position(0.0f,0.0f , -30.0f );


    // Direction de la caméra vers le centre de la boîte
    Vector3f box_center(0.0f, 0.0f , 0.0f);
    Vector3f camera_direction = (box_center - camera_position).normalize();
    Camera camera(camera_position, camera_direction);

    //ceci est nécessaire car on ne parvenait pas à mettre la cam dans la bonne direction 
    camera.set_camera_angle(90.0f,0.0f ) ; 
    scene.set_camera(camera) ; 


    // source lumineuse au dessus de la boite
    // Ajouter une lumière blanche au-dessus de la boîte
    scene.add_light(Light(
    Vector3f(0.0f, 10.0f, 0.0f),   // Position
    Vector3f(0.2f, 0.2f, 0.2f),   // Composante ambiante (faible éclairage)
    Vector3f(0.8f, 0.8f, 0.8f),   // Composante diffuse (éclairage principal)
    Vector3f(1.0f, 1.0f, 1.0f)    // Composante spéculaire (éclat)
    )) ;
    // Ajouter une deuxième lumière
    scene.add_light(Light(
    Vector3f(-5.0f, 10.0f, -5.0f),
    Vector3f(0.1f, 0.1f, 0.1f),
    Vector3f(0.6f, 0.3f, 0.3f),
    Vector3f(1.0f, 0.5f, 0.5f)
)) ; 
    Ray3f light_source(Vector3f(0.0f, box_size, 0.0f), Vector3f(0.0f, -1.0f, 0.0f));
    scene.set_source(light_source);
  
  Material red(
    Vector3f(0.2f, 0.0f, 0.0f), // Coefficient ambiant
    Vector3f(1.0f, 0.0f, 0.0f), // Coefficient diffus
    Vector3f(0.5f, 0.0f, 0.0f), // Coefficient spéculaire
    0.5f // Brillance
  );

  Material green(
    Vector3f(0.0f, 0.2f, 0.0f), // Coefficient ambiant
    Vector3f(0.0f, 1.0f, 0.0f), // Coefficient diffus
    Vector3f(0.0f, 0.5f, 0.0f), // Coefficient spéculaire
    0.5f // Brillance
  ) ;
  Material blue(
    Vector3f(0.0f, 0.0f, 0.2f), // Coefficient ambiant
    Vector3f(0.0f, 0.0f, 1.0f), // Coefficient diffus
    Vector3f(0.0f, 0.0f, 0.5f), // Coefficient spéculaire
    0.5f // Brillance
  );
  Material gray(
    Vector3f(0.2f, 0.2f, 0.2f), // Coefficient ambiant
    Vector3f(0.5f, 0.5f, 0.5f), // Coefficient diffus
    Vector3f(0.3f, 0.3f, 0.3f), // Coefficient spéculaire
    0.5f // Brillance
  );
  Material white(
    Vector3f(0.5f, 0.5f, 0.5f), // Coefficient ambiant
    Vector3f(1.0f, 1.0f, 1.0f), // Coefficient diffus
    Vector3f(0.8f, 0.8f, 0.8f), // Coefficient spéculaire
    0.5f // Brillance
  );



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
    Sphere sphere(Vector3f(6, 0.0f, 0.0f), 3.0f, Material(Vector3f(1.0f, 0.0f, 0.0f),Vector3f(1.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.5f, 0.0f), 0.7f));
    scene.add_object(&sphere);


    // ajout d'un cube 
    float cube_size = 2.0f ; 
    //Material cube_material(Vector3f(0.0f, 1.0f, 0.0f), 0.5f);
    Material cube_material(
    Vector3f(0.0f, 0.2f, 0.0f), // Coefficient ambiant
    Vector3f(0.0f, 1.0f, 0.0f), // Coefficient diffus
    Vector3f(0.0f, 0.5f, 0.0f), // Coefficient spéculaire
    0.5f // Brillance
  );
    Cub_quad frontc(Vector3f(-cube_size, -cube_size, cube_size), Vector3f(2.0f * cube_size, 0.0f, 0.0f), Vector3f(0.0f, 2.0f * cube_size, 0.0f), cube_material);
    Cub_quad backc(Vector3f(-cube_size, -cube_size, -cube_size), Vector3f(2.0f * cube_size, 0.0f, 0.0f), Vector3f(0.0f, 2.0f * cube_size, 0.0f), cube_material);
    Cub_quad leftc(Vector3f(-cube_size, -cube_size, -cube_size), Vector3f(0.0f, 2.0f * cube_size, 0.0f), Vector3f(0.0f, 0.0f, 2.0f * cube_size), cube_material); 
    Cub_quad rightc(Vector3f(cube_size, -cube_size, -cube_size), Vector3f(0.0f, 2.0f * cube_size, 0.0f), Vector3f(0.0f, 0.0f, 2.0f * cube_size), cube_material); 
    Cub_quad topc(Vector3f(-cube_size, cube_size, -cube_size), Vector3f(2.0f * cube_size, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 2.0f * cube_size), cube_material) ;
    Cub_quad bottomc(Vector3f(-cube_size, -cube_size, -cube_size), Vector3f(2.0f * cube_size, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 2.0f * cube_size), cube_material) ;


    scene.add_object(&frontc);
    scene.add_object(&leftc);
    scene.add_object(&rightc);
    scene.add_object(&topc);
    scene.add_object(&bottomc);
  // Générer l'image (matrice de couleurs)
    std::vector<std::vector<Vector3f>> image(height, std::vector<Vector3f>(width));
    scene.render_to_image(width, height, image);

  //afficher l'image avec sdl 

  while( sdl.handle_events()){
    sdl.render(image) ; 
  }

    return 0 ; 

}