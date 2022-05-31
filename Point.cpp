

#include "Point.h"


Point::Point(int x, int y):m_x(x), m_y(y){}

Point::Point(const Point &other):m_x(other.m_x),m_y(other.m_y) {}

Point::~Point()= default;


int Point::getX() const {return m_x;}
int Point::getY() const {return m_y;}


void Point::setX(int x) {m_x = x;}
void Point::setY(int y) {m_y = y;}
void Point::setPoint(int x, int y) {m_x = x; m_y = y;}
void Point::setPoint(const Point &other) {m_x = other.m_x; m_y = other.m_y;}




bool Point::operator==(const Point &other) const {
    if (m_x == other.m_x && m_y == other.m_y)
        return true;
    return false;
}

bool Point::operator!=(const Point &other) const {
    if (m_x != other.m_x && m_y != other.m_y)
        return true;
    return false;}


//returns a new point with updated x(x+num) and y(y+num)
Point Point::operator+(int num) const {
    Point* newPoint;
    newPoint = new Point[sizeof(Point)];
    newPoint->m_x = (m_x+num);
    newPoint->m_y = (m_y+num);
    return *newPoint;
}

//updates the point with x(x+num) and y(y+num) and returns the updated point
const Point &Point::operator+=(int num) {
    this->m_x = (m_x+num);
    this->m_y = (m_y+num);
    return *this;
}

//returns the sum of x and y
Point::operator int() const {
    int sum = m_x + m_y;
    return sum;
}

//adds coordinates (x,y) and returns a new point
Point Point::operator+(const Point &other) const {
    Point* point;
    point = new Point[sizeof(Point)];
    point->setX(m_x+other.m_x);
    point->setY(m_y+other.m_y);
    return *point;
}

//adds 1 to x and y and returns the updated point - postfix
Point Point::operator++(int) {
    this->m_x++;
    this->m_y++;
    return *this;
}

//adds 1 to x and y and returns the updated point - prefix
const Point &Point::operator++() {
    ++this->m_x;
    ++this->m_y;
    return *this;
}

//returns a new point with (x,y)*num
Point operator*(int num, const Point &other) {
    Point point;
    point.setX(other.m_x*num);
    point.setY(other.m_y*num);
    return point;
}
