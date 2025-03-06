#include "circle.h"
#include <cmath>
#include <stdexcept>

Circle::Circle(double r) {
    if (r < 0) {
        throw std::invalid_argument("Radius cannot be negative");
    }
    radius = r;
    calculateCircumference();
    calculateArea();
}

void Circle::setRadius(double r) {
    if (r < 0) {
        throw std::invalid_argument("Radius cannot be negative");
    }
    radius = r;
    calculateCircumference();
    calculateArea();
}

void Circle::setCircumference(double c) {
    if (c < 0) {
        throw std::invalid_argument("Circumference cannot be negative");
    }
    radius = c / (2 * M_PI);
    calculateCircumference(); // Добавляем обновление circumference
    calculateArea();          // Добавляем обновление area
}

void Circle::setArea(double a) {
    if (a < 0) {
        throw std::invalid_argument("Area cannot be negative");
    }
    radius = sqrt(a / M_PI);
    calculateCircumference(); // Добавляем обновление circumference
    calculateArea();          // Добавляем обновление area
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getCircumference() const {
    return circumference;
}

double Circle::getArea() const {
    return area;
}

void Circle::calculateCircumference() {
    circumference = 2 * M_PI * radius;
}

void Circle::calculateArea() {
    area = M_PI * radius * radius;
}
