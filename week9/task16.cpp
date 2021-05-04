#include <iostream>
using namespace std;

class Vector2D
{
public:
    Vector2D();
    Vector2D(int x, int y);
    int getX() const;
    int getY() const;
    void output() const;
private:
    int vectorX;
    int vectorY;    
};

const Vector2D operator +(const Vector2D& vector1, const Vector2D& vector2);
const Vector2D operator -(const Vector2D& vector1, const Vector2D& vector2);
bool operator ==(const Vector2D& vector1, const Vector2D& vector2);

int main()
{
    Vector2D v0, v1(2,2), v2(3,3), v3;

    v3 = v1 + v2;
    v3.output();

    v3 = v2 - v2;
    v3.output();

    if (v3 == v0)
        cout << "Operator - works!";

    return 0;
}

const Vector2D operator +(const Vector2D& vector1, const Vector2D& vector2)
{
    int resultX = vector1.getX() + vector2.getX();
    int resultY = vector1.getY() + vector2.getY();
    return Vector2D(resultX, resultY);
}

const Vector2D operator -(const Vector2D& vector1, const Vector2D& vector2)
{
    int resultX = vector1.getX() - vector2.getX();
    int resultY = vector1.getY() - vector2.getY();
    return Vector2D(resultX, resultY);
}

bool operator ==(const Vector2D& vector1, const Vector2D& vector2)
{
    return ((vector1.getX() == vector2.getX()) && (vector1.getY() == vector2.getY()));
}

Vector2D::Vector2D() : vectorX(0), vectorY(0) {}
Vector2D::Vector2D(int x, int y) : vectorX(x), vectorY(y) {}
int Vector2D::getX() const { return vectorX; }
int Vector2D::getY() const { return vectorY; }
void Vector2D::output() const
{
    cout << "(" << vectorX << "," << vectorY << ")" << endl;
    return;
}