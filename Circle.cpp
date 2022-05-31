

#include "Circle.h"

Circle::Circle(double r, const char *sn): Shape(sn)
{
    setRadius(r);
}

Circle::Circle(const Circle &other): Shape(other.getName()) {setRadius(other.getRadius()) ;}

Circle::~Circle() = default;

double Circle::getRadius() const {return m_radius;}

void Circle::setRadius(double r) {m_radius = r;}

int Circle::calcArea() const {
    int area = PI*m_radius*m_radius;
    return area;
}

int Circle::calcPerimeter() const {
    int perimeter = PI*m_radius*2;
    return perimeter;
}

Circle operator+(int r, const Circle &other) {
    Circle newCircle;
    newCircle.setRadius(other.m_radius + r);
    newCircle.setName(other.getName());
    newCircle.setCenter(other.getCenter());
    return newCircle;
}

//operator= that copies all
const Circle &Circle::operator=(const Circle &other) {
    this->setName(other.getName());
    this->setCenter(other.getCenter());
    this->setRadius(other.getRadius());
    return *this;
}


//updates only the name of the shape and returns the updated shape
const Circle &Circle::operator=(const char *name) {
    this->setName(name);
    return *this;
}

