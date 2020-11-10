#pragma once
#include <iostream> 

class Vector2D
{
public:
    Vector2D ();
    Vector2D (float x, float y);
    float x;
    float y;

    Vector2D& Zero();

    Vector2D& Add(const Vector2D& other);
    Vector2D& Subtract(const Vector2D& other);
    Vector2D& Divide(const Vector2D& other);
    Vector2D& Divide(const float& value);
    Vector2D& Multiply(const Vector2D& other);
    Vector2D& Multiply(const float& value);
    
    Vector2D operator+(const Vector2D& v2);
    Vector2D operator-(const Vector2D& v2);
    Vector2D operator/(const Vector2D& v2);
    Vector2D operator/(const float& value);
    Vector2D operator*(const Vector2D& v2);
    Vector2D operator*(const float &value);
    bool operator==(const Vector2D& v2);
    
    Vector2D& operator+=(const Vector2D& other);
    Vector2D& operator-=(const Vector2D& other);
    Vector2D& operator/=(const Vector2D& other);
    Vector2D& operator/=(const float& value);
    Vector2D& operator*=(const Vector2D& other);
    Vector2D& operator*=(const float& value);

    

    friend std::ostream& operator<<(std::ostream& stream, const Vector2D& vec);
};
