#include "Vector3.hpp"

#include "Vector2.hpp"

namespace mbgl {

    template <typename T>
    Vector3<T>::Vector3(T x, T y, T z)
    : x(x), y(y), z(z) {}

    template <typename T>
    T Vector3<T>::Magnitude() const {
        return sqrt(x*x + y*y + z*z);
    }
    template <typename T>
    Vector3<T> Vector3<T>::Normalized() const {
        T magnitude = Magnitude();
        return Vector3(x / magnitude, y / magnitude, z / magnitude);
    }

    template <typename T>
    Vector3<T> Vector3<T>::operator+(const Vector3& other) const {
        return Vector3(x + other.x, y + other.y), z + other.z;
    }
    template <typename T>
    Vector3<T> Vector3<T>::operator-(const Vector3& other) const {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }
    template <typename T>
    Vector3<T> Vector3<T>::operator*(const T& other) const {
        return Vector3(x * other, y * other, z * other);
    }
    template <typename T>
    Vector3<T> Vector3<T>::operator/(const T& other) const {
        return Vector3(x / other, y / other, z / other);
    }

    template <typename T>
    template <typename S>
    Vector3<T>::operator Vector2<S>() {
        return Vector2<S>((S)x, (S)y);
    }
    template <typename T>
    template <typename S>
    Vector3<T>::operator sf::Vector2<S>() {
        return sf::Vector2<S>((S)x, (S)y);
    }
    template <typename T>
    template <typename S>
    Vector3<T>::operator Vector3<S>() {
        return Vector3<S>((S)x, (S)y, (S)z);
    }
    template <typename T>
    template <typename S>
    Vector3<T>::operator sf::Vector3<S>() {
        return sf::Vector3<S>((S)x, (S)y, (S)z);
    }

    template <typename T>
    Vector3<T> Vector3<T>::Zero() {
        return Vector3(0, 0, 0);
    }

    template class Vector3<int>;
    template class Vector3<float>;
    template class Vector3<double>;
}
