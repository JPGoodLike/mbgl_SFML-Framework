#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <math.h>

namespace mbgl {
    template <typename T>
    class Vector2;

    template<typename T>
    class Vector3 {
    public:
        T x, y, z;
        Vector3(T x = 0, T y = 0, T z = 0);

        T Magnitude() const;
        Vector3 Normalized() const;

        Vector3 operator+(const Vector3& other) const;
        Vector3 operator-(const Vector3& other) const;
        Vector3 operator*(const T& other) const;
        Vector3 operator/(const T& other) const;
        friend std::ostream& operator<<(std::ostream& stream, const Vector3 other) {
            stream << other.x << " " << other.y << " " << other.z;
            return stream;
        }

        template <typename S>
        operator Vector2<S>();
        template <typename S>
        operator sf::Vector2<S>();
        template <typename S>
        operator Vector3<S>();
        template <typename S>
        operator sf::Vector3<S>();

        static Vector3 Zero();
    };

    using vec3 = Vector3<float>;
    using vec3i = Vector3<int>;
    using vec3d = Vector3<double>;
}