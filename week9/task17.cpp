#include <iostream>
using namespace std;

class Vector2D
{
public:
    Vector2D();
    Vector2D(int x, int y);
    void output() const;
    friend const Vector2D operator +(const Vector2D& vector1, const Vector2D& vector2);
    friend const Vector2D operator -(const Vector2D& vector1, const Vector2D& vector2);
    friend bool operator ==(const Vector2D& vector1, const Vector2D& vector2);
    friend const Vector2D operator *(const int scalar, const Vector2D& vector2);
    const int operator *(const Vector2D& vector2) const;
private:
    int vectorX;
    int vectorY;    
};

int main()
{
    Vector2D v0, v1(2,2), v2(3,3), v3;
    int k = 2;
    v3 = k*v1;
    v3.output();
    cout << v1 * v2 << endl;
    return 0;
}

const Vector2D operator +(const Vector2D& vector1, const Vector2D& vector2)
{
    int resultX = vector1.vectorX + vector2.vectorX;
    int resultY = vector1.vectorY + vector2.vectorY;
    return Vector2D(resultX, resultY);
}

const Vector2D operator -(const Vector2D& vector1, const Vector2D& vector2)
{
    int resultX = vector1.vectorX - vector2.vectorX;
    int resultY = vector1.vectorY - vector2.vectorY;
    return Vector2D(resultX, resultY);
}

bool operator ==(const Vector2D& vector1, const Vector2D& vector2)
{
    return ((vector1.vectorX == vector2.vectorX) && (vector1.vectorY == vector2.vectorY));
}

const Vector2D operator *(const int scalar, const Vector2D& vector2)
{
    int resultX = scalar * vector2.vectorX;
    int resultY = scalar * vector2.vectorY;
    return Vector2D(resultX, resultY);
}

Vector2D::Vector2D() : vectorX(0), vectorY(0) {}
Vector2D::Vector2D(int x, int y) : vectorX(x), vectorY(y) {}
void Vector2D::output() const
{
    cout << "(" << vectorX << "," << vectorY << ")" << endl;
    return;
}
const int Vector2D::operator *(const Vector2D& vector2) const
{
    int resultX = vectorX * vector2.vectorX;
    int resultY = vectorY * vector2.vectorY;
    return resultX + resultY;
}