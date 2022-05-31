


#include "Square.h"

//constructor. center point = (0,0), name=sn
Square::Square(double up, double down, double right, double left, const char *sn): Quad(up, down, right, left, sn) {}

Square::~Square() = default;

//shifts the center of the square by x (right and left)
void Square::shiftX(int x) {this->getCenter().operator+=(x);}

void Square::shiftY(int y) {this->getCenter().operator+=(y);}
