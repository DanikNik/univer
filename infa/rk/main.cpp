#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

class Point{
public:
    float x;
    float y;
    Point(float x, float y){
        this -> x = x;
        this -> y = y;
    }
    void move(float dx, float dy){
        this -> x += dx;
        this -> y += dy;
    }
};

float calc_dist(Point &p1, Point &p2){
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

int main(){
    Point p1 = Point(1, 2);
    Point p2 = Point(3, 4);
    float dist = calc_dist(p1, p2);
    cout << dist << endl;
}
