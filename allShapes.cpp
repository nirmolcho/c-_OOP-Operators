

#include "allShapes.h"
#include "Shape.h"
#include "Circle.h"
#include "Quad.h"
#include "Square.h"



allShapes::allShapes() {
    m_arr = nullptr;
    m_size = 0;
}

allShapes::allShapes(const allShapes &other)
{
    m_arr = new Shape*[other.getSize()];
    for (int i = 0; i < m_size;i++){
        if (typeid(other[i]) == typeid(Circle))
        {
            Circle *newC = dynamic_cast<Circle *>(other.m_arr[i]);
            m_arr[i] = new Circle(*newC);
        }
        if (typeid(other[i]) == typeid(Quad))
        {
            Quad *newC = dynamic_cast<Quad *>(other.m_arr[i]);
            m_arr[i] = new Quad(*newC);
        }
        if (typeid(other[i]) == typeid(Square))
        {
            Square *newC = dynamic_cast<Square *>(other.m_arr[i]);
            m_arr[i] = new Quad(*newC);
        }
    }
    m_size = other.getSize();
}

allShapes::~allShapes() {
    if (m_size != 0) {
        for (int i = 0; i < m_size; i++)
            delete[] m_arr[i];
        delete m_arr;
    }
}

int allShapes::getSize() const {
    return m_size;
}

void allShapes::addShape(Shape *newShape)
{
    Shape **newArr;
    newArr = new Shape*[m_size+1];
    int i;
    for (i = 0; i < m_size; i++) {
        newArr[i] = m_arr[i];
    }
        if(typeid(*newShape) == typeid(Circle))
        {
            Circle *newC = dynamic_cast<Circle*>(newShape);
            newArr[i] = new Circle(*newC);
        }
        if(typeid(*newShape) == typeid(Quad))
        {
            Quad *newQ = dynamic_cast<Quad *>(newShape);
            newArr[i] = new Quad(*newQ);
        }
        if(typeid(*newShape) == typeid(Square)){
            Square *newSQ = dynamic_cast<Square *>(newShape);
            newArr[i] = new Square(*newSQ);
        }
    m_arr = newArr;
    m_size++;
}

void allShapes::removeShape(int index) {
    if (m_size == 0)
        return;
    Shape **newShape;
    newShape = new Shape *[m_size - 1];
    int i, j;
    for (i = 0, j = 0; i < m_size; i++) {
        if (i != index) {
            newShape[j] = m_arr[i];
        } else {
            i++;
            newShape[j] = m_arr[i];
            delete m_arr[index];
        }
        j++;
    }
    m_arr = newShape;
    m_size--;
}

int allShapes::totalArea() const {
    int sum = 0;
    for (int i = 0; i < m_size; i++){
       sum += m_arr[i]->calcArea();
    }
    return sum;
}

int allShapes::totalPerimeter() const {
    int sum = 0;
    for (int i = 0; i < m_size;i++){
        if(typeid(*m_arr[i]) == typeid(Circle))
            sum = sum + m_arr[i]->calcPerimeter();
        if(typeid(*m_arr[i]) == typeid(Quad))
            sum = sum + m_arr[i]->calcPerimeter();
        if(typeid(*m_arr[i]) == typeid(Square))
            sum = sum +m_arr[i]->calcPerimeter();
    }
    return sum;
}

int allShapes::totalCircleArea() const {
    int sum = 0;
    for (int i = 0; i < m_size;i++)
        if(typeid(*m_arr[i]) == typeid(Circle))
            sum = sum + m_arr[i]->calcArea();
    return sum;
}

int allShapes::totalSquarePerimeter() const {
    int sum = 0;
    for (int i = 0; i < m_size;i++)
        if(typeid(*m_arr[i]) == typeid(Square))
            sum = sum + m_arr[i]->calcPerimeter();
    return sum;
}

const allShapes &allShapes::operator+=(Shape *newS) {
    this->addShape(newS);
    return *this;
}

//returns the shape located at index ind
Shape *allShapes::operator[](int ind) const {
    return m_arr[ind];
}

allShapes allShapes::operator+(const allShapes &other) const {
    allShapes *newAllShapes;
    newAllShapes = new allShapes(*this);
    for (int i = 0; i < other.getSize(); ++i)
    {
        newAllShapes->addShape(other.m_arr[i]);
    }
    return *newAllShapes;
}

allShapes::operator int() const {
    return this->getSize();
}
