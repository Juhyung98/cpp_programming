#include <iostream>
using namespace std;

class Figure{
    public:
        virtual void draw() = 0;    
};

class Point{
    public:
        int x;
        int y;
        
        Point();
        Point(int xx, int yy);
};     
Point::Point(): x(0), y(0) {};
Point::Point(int xx, int yy): x(xx), y(yy) {};

class Rectangle : public Figure{
    public:
        Point p1;
        Point p2;
        Rectangle(Point pp1, Point pp2);
        void draw();
};
Rectangle::Rectangle(Point pp1, Point pp2) :  p1(pp1), p2(pp2) {};

void Rectangle::draw(){
    cout << "A rectangle from " << "(" << p1.x << "," << p2.y << ") to (" << p2.x << "," << p2.y << ")\n";
    return;
}

class Circle: public Figure{
    public:
        Point o;
        int r2;
        Circle(Point pp1, int pp2);
        void draw();
};

Circle::Circle(Point pp1, int pp2): o(pp1), r2(pp2) {};

void Circle::draw(){
    cout << "A circle with the center of (" <<  o.x << "," << o.y << ") and the radius of "<< r2;
    return;
}

void draw2figues (Figure& f1, Figure& f2)
{
    cout << "First figure is: ";
    f1.draw();
    cout << "Second figure is: ";
    f2.draw();
    return;
}

int main ()
{
    Point p1(0,0), p2(2,2);
    Rectangle r1 (p1, p2);
    Circle c1 (p1, 2);
    draw2figues(r1, c1);
    return 0;
}