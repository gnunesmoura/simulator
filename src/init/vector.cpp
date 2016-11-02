#include <init/vector.hpp>

Vector::Vector (Node a, Node b, double norm) {
    double xC, yC, normC, divider;

    xC = b.get(Axis::x) - a.get(Axis::x);
    yC = b.get(Axis::y) - a.get(Axis::y);
    normC = calcNorm(xC, yC);
    divider = normC/norm;
    xC /= divider;
    yC /= divider;

    this->x = xC;
    this->y = yC;
}

Vector::Vector (double x, double y) {
    this->x = x;
    this->y = y;
}

double Vector::getNorm () {
    return calcNorm(x, y);
}

inline double Vector::calcNorm (double x, double y) {
    return sqrt ( (x*x) + (y * y) );
}

double Vector::get(Axis a) {
    if(a == Axis::x) return this->x;
    else return this->y;
}

Vector Vector::operator+ (Vector b) {
    double xB, yB;
    xB = b.get(Axis::x);
    yB = b.get(Axis::y);
    Vector c (this->x + xB, this->y + yB);
    return c;
}

Vector Vector::operator* (double scalar) {
    Vector b(this->x*scalar, this->y*scalar);
    return b;
}

void Vector::print () {
        std::cout << "x = " << this->x;
        std::cout << " y = " << this->y;
        std::cout << " norm = " << getNorm() << std::endl;
}