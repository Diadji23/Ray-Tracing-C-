#ifndef VECTOR3F_H
#define VECTOR3F_H

#include <cmath>

/**
 * @class Vector3f
 * @brief Représente un vecteur 3D.
 * 
 * Cette classe est utilisée pour manipuler des vecteurs 3D dans le cadre
 * de calculs mathématiques liés au lancer de rayons.
 */

class Vector3f {

    private:

    float x; //coordonnée 1
    float y; //coordonnée 2
    float z; //coordonnée 3

    public:
    /**
     * @brief Constructeur par défaut.
     * 
     * Initialise le vecteur à (0, 0, 0).
     */
    Vector3f();

    /**
     * @brief Constructeur
     * 
     *@param x coordonnée 1 du vecteur
     *@param y coordonnée 2 du vecteur
     *@param Z coordonnée 3 du vecteur
     * Initialise le vecteur à (0, 0, 0).
     */
    Vector3f(float x, float y, float z);

    /**
     * @brief Obtient la coordonnée X du vecteur.
     * 
     * @return La coordonnée X.
     */
    float getX() const;

    /**
     * @brief Obtient la coordonnée Y du vecteur.
     * 
     * @return La coordonnée Y.
     */
    float getY() const;

    /**
     * @brief Obtient la coordonnée Z du vecteur.
     * 
     * @return La coordonnée Z.
     */
    float getZ() const;

    /**
     * @brief Additionne deux vecteurs.
     * 
     * @param other Le vecteur à ajouter.
     * @return Un nouveau vecteur résultant de l'addition.
     */
    Vector3f operator+(const Vector3f& other) const;

    /**
     * @brief Soustrait deux vecteurs.
     * 
     * @param other Le vecteur à soustraire.
     * @return Un nouveau vecteur résultant de la soustraction.
     */
    Vector3f operator-(const Vector3f& other) const;

    /**
     * @brief Multiplie le vecteur par un scalaire.
     * 
     * @param scalar Le scalaire par lequel multiplier.
     * @return Un nouveau vecteur résultant de la multiplication.
     */
    Vector3f operator*(float scalar) const;

    /**
     * @brief Calcule le produit scalaire avec un autre vecteur.
     * 
     * @param other Le vecteur avec lequel effectuer le produit scalaire.
     * @return Le produit scalaire (un scalaire).
     */
    float dot(const Vector3f& other) const;



    Vector3f cross(const Vector3f& other) const ;

    /**
     * @brief Normalise le vecteur.
     * 
     * @return Un vecteur normalisé (de longueur 1).
     */
    Vector3f normalize() const;
    /**
     * @brief calcul la norme du vecteur.
     * 
     * @return renvoie la norme du vecteur
     */
    float magnitude() const;




    // Setters pour les composantes x, y, et z
     void set_x(float new_x) { x = new_x; } 
    void set_y(float new_y) { y = new_y; }
     void set_z(float new_z) { z = new_z; }
};

#endif