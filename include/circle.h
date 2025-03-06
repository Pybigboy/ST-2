#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
    double radius;
    double circumference;
    double area;

    void calculateCircumference();
    void calculateArea();

public:
    Circle(double r);
    void setRadius(double r);
    void setCircumference(double c);
    void setArea(double a);
    double getRadius() const;
    double getCircumference() const;
    double getArea() const;
};

#endif // CIRCLE_H