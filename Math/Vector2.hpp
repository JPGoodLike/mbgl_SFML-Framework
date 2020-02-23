#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <math.h>

namespace mbgl {
    template<typename T>
    class Vector3;

    template<typename T>
    class Vector2 {
    public:
        T x, y;
        Vector2(T x = 0, T y = 0);

        T Magnitude() const;
        Vector2 Normalized() const;

        Vector2 Rotate(T angle) const;

        Vector2 operator+(const Vector2& other) const;
        Vector2 operator-(const Vector2& other) const;
        Vector2 operator*(const T& other) const;
        Vector2 operator/(const T& other) const;
        friend std::ostream& operator<<(std::ostream& stream, const Vector2 other) {
            stream << other.x << " " << other.y;
            return stream;
        }

        template <typename S>
        operator Vector2<S>();
        template <typename S>
        operator sf::Vector2<S>();
        template <typename S>
        operator Vector3<S>();

        static Vector2 Zero();
    };

    using vec2 = Vector2<float>;
    using vec2i = Vector2<int>;
    using vec2d = Vector2<double>;
}