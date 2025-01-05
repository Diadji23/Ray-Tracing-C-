class Light {
private:
    Vector3f position_;
    Vector3f direction_;
    float intensity_;  // Intensité de la lumière (0.0 à 1.0 ou supérieur pour des effets lumineux)
public:
    Light(const Vector3f& position, const Vector3f& direction, float intensity)
        : position_(position), direction_(direction), intensity_(intensity) {}

    float get_intensity() const { return intensity_; }
    Vector3f get_position() const { return position_; }
    Vector3f get_direction() const { return direction_; }
};
