#include "Vector2D.h"

Vector2D::Vector2D()
{
    x = y = 0.0f;
}
Vector2D::Vector2D (float x, float y)
{
    this->x = x;
    this->y = y;
}

#pragma region Vector2D Functions
Vector2D& Vector2D::Zero ()
{
    x = y = 0;
    return *this;
}
#pragma endregion

#pragma region Base Operations
Vector2D& Vector2D::Add(const Vector2D& other)
{
    this->x += other.x;
    this->y += other.y;
    return *this;
}
Vector2D& Vector2D::Subtract(const Vector2D& other)
{
    this->x -= other.x;
    this->y -= other.y;
    return *this;
}
Vector2D& Vector2D::Multiply(const Vector2D& other)
{
    this->x *= other.x;
    this->y *= other.y;
    return *this;
}
Vector2D& Vector2D::Multiply(const float& value)
{
    this->x *= value;
    this->y *= value;
    return *this;
}
Vector2D& Vector2D::Divide(const Vector2D& other)
{
    this->x /= other.x;
    this->y /= other.y;
    return *this;
}
Vector2D& Vector2D::Divide(const float& value)
{
    this->x /= value;
    this->y /= value;
    return *this;
}
#pragma endregion

#pragma region Operators
Vector2D Vector2D::operator+  (const Vector2D& v2)
{
    return Vector2D(this->x + v2.x, this->y + v2.y);
    
}
Vector2D Vector2D::operator-  (const Vector2D& v2)
{
    return Vector2D(this->x -v2.x, this->y - v2.y);
}
Vector2D Vector2D::operator*  (const Vector2D& v2)
{
    return Vector2D(this->x * v2.x, this->y * v2.y);
}
Vector2D Vector2D::operator*  (const float &value)
{
    return Vector2D(this->x * value, this->y * value);
}
Vector2D Vector2D::operator/  (const Vector2D& v2)
{
    return Vector2D(this->x / v2.x, this->y / v2.y);
}
Vector2D Vector2D::operator/  (const float& value)
{
    return Vector2D(this->x / value, this->y / value);
}
bool     Vector2D::operator== (const Vector2D& v2)
{
    return this->x == v2.x && this->y == v2.y;
}

Vector2D& Vector2D::operator+= (const Vector2D& other)
{
    return this->Add(other);
}
Vector2D& Vector2D::operator-= (const Vector2D& other)
{
    return this->Subtract(other);
}
Vector2D& Vector2D::operator/= (const Vector2D& other)
{
    return this->Divide(other);
}
Vector2D& Vector2D::operator/= (const float& value)
{
    return this->Divide(value);
}
Vector2D& Vector2D::operator*= (const Vector2D& other)
{
    return this->Multiply(other);
}
Vector2D& Vector2D::operator*= (const float& value)
{
    return this->Multiply(value);
}
std::ostream& operator<<(std::ostream& stream, const Vector2D& vec)
{
    return stream << "(" << vec.x << "," << vec.y << ")";
}
#pragma endregion

