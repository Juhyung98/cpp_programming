#include <iostream>
#include <vector>
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
        virtual void draw();
};
Rectangle::Rectangle(Point pp1, Point pp2) :  p1(pp1), p2(pp2) {};

void Rectangle::draw(){
    cout << "A rectangle from " << "(" << p1.x << "," << p1.y << ") to (" << p2.x << "," << p2.y << ")\n";
    return;
}

class Circle: public Figure{
    public:
        Point o;
        int r2;
        Circle(Point pp1, int pp2);
        virtual void draw();
};
Circle::Circle(Point pp1, int pp2): o(pp1), r2(pp2) {};

void Circle::draw(){
    cout << "A circle with the center of (" <<  o.x << "," << o.y << ") and the radius of "<< r2 << "\n";
    return;
}

int main ()
{
    vector<Figure*> v_figure;
    string buffer;

    while(1)
    {
        cout << "Enter figure type or draw: " ;
        cin >> buffer;

        if(buffer == "rectangle"){
            int x, y, x2 ,y2;
            cout << "Enter x, y coordinates of P1: "; 
            cin >> x >> y;
            cout << "Enter x, y coordinates of P2: "; 
            cin >> x2 >> y2;
            Rectangle *r1;
            r1 = new Rectangle(Point(x,y),Point(x2,y2));
            v_figure.push_back(r1);
        }
        else if(buffer == "circle"){
            int x, y, r;
            cout << "Enter x,y coordinates of center: ";
            cin >> x >> y;
            cout << "Enter the radius: ";
            cin >> r;
            Circle *c1;
            c1 = new Circle(Point(x,y),r);
            v_figure.push_back(c1);
        }
        else if(buffer == "draw"){
            for(int i=0; i<v_figure.size(); i++){
                v_figure[i]->draw();
            }
            break;
        }
    }
    return 0;
}