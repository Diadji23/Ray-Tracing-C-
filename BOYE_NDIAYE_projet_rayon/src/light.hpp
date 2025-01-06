#include "vector3f.hpp"
struct Light {
    Vector3f position;
    Vector3f ambient;
    Vector3f diffuse;
    Vector3f specular;

    Light(const Vector3f& pos, const Vector3f& amb, const Vector3f& diff, const Vector3f& spec)
        : position(pos), ambient(amb), diffuse(diff), specular(spec) {}
};
