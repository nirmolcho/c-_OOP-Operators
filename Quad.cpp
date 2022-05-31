#include "Quad.h"


//constructor. center point = (0,0), name=sn
Quad::Quad(double up, double down, double right, double left, const char *sn): Shape(sn)
{
    m_up = up;
    m_down = down;
    m_right = right;
    m_left = left;
}

Quad::Quad(const Quad &other): Shape(other.getName()) {
    m_left = other.m_left;
    m_right = other.m_right;
    m_up = other.m_up;
    m_down = other.m_down;
}

Quad::~Quad() = default;

int Quad::calcArea() const {
    int area = m_right*m_up;
    return area;
}

int Quad::calcPerimeter() const {
    return (m_right+m_up+m_down+m_left);
}

