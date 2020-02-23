#include "Vector2.hpp"

#include "Vector3.hpp"

namespace mbgl {

    template<typename T>
    Vector2<T>::Vector2(T x, T y)
    : x(x), y(y) {}

    template <typename T>
    T Vector2<T>::Magnitude() const {
        return sqrt(pow(this->x, 2) + pow(this->y, 2));
    }
    template <typename T>
    Vector2<T> Vector2<T>::Normalized() const {
        T magnitude = this->Magnitude();
        return Vector2(this->x / magnitude, this->y / magnitude);
    }

    template <typename T>
    Vector2<T> Vector2<T>::Rotate(T angle) const {
        return Vector2(x*cos(angle) - y*sin(angle), x*sin(angle) + y*cos(angle));
    }

    template <typename T>
    Vector2<T> Vector2<T>::operator+(const Vector2& other) const {
        return Vector2(this->x + other.x, this->y + other.y);
    }
    template <typename T>
    Vector2<T> Vector2<T>::operator-(const Vector2& other) const {
        return Vector2(this->x - other.x, this->y - other.y);
    }
    template <typename T>
    Vector2<T> Vector2<T>::operator*(const T& other) const {
        return Vector2(this->x * other, this->y * other);
    }
    template <typename T>
    Vector2<T> Vector2<T>::operator/(const T& other) const {
        return Vector2(this->x / other, this->y / other);
    }

    template <typename T>
    template <typename S>
    Vector2<T>::operator Vector2<S>() {
        return Vector2<S>((S)x, (S)y);
    }
    template <typename T>
    template <typename S>
    Vector2<T>::operator sf::Vector2<S>() {
        return sf::Vector2<S>((S)x, (S)y);
    }
    template <typename T>
    template <typename S>
    Vector2<T>::operator Vector3<S>() {
        return Vector3<S>((S)x, (S)y, 0);
    }

    template <typename T>
    Vector2<T> Vector2<T>::Zero() {
        return Vector2(0, 0);
    }

    template class Vector2<int>;
    template class Vector2<float>;
    template class Vector2<double>;
}