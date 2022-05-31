


#include "Shape.h"
#include "Circle.h"
#include "Quad.h"
int Shape::s_totalNumOfShapes = 0;

//Creates a new shape (name=sn,centerPoint = (0,0))
Shape::Shape(const char *sn){
    s_totalNumOfShapes++;
    this->setName(sn);
    setCenter(Point(0,0));
}

Shape::Shape(const Shape &other){
    s_totalNumOfShapes++;
    *this = other;
}

Shape::~Shape() {
    if (m_shapeName != nullptr)
        delete[] m_shapeName;
    s_totalNumOfShapes--;
}

void Shape::setName(const char *name) {
    m_shapeName = new char[strlen(name)+1];
    strcpy(m_shapeName,name);
}

void Shape::setCenter(const Point &p) {
    m_centerPoint.setPoint(p.getX(),p.getY());
}

const char *Shape::getName() const {return m_shapeName;}

Point Shape::getCenter() const {return m_centerPoint;}

void Shape::setShape(const char *sn, const Point &other) {
    setName(sn);
    m_centerPoint.setPoint(other.getX(),other.getY());
}

int Shape::numOfShapes() {return s_totalNumOfShapes;}

const Shape &Shape::operator=(const Shape &other) {
    if (this == &other)
        return *this;
    setName(m_shapeName);
    return *this;
}
