#include "tasks.h"
#include "circle.h"

double calculateGap(double earthRadius, double addedLength) {
    Circle earth(earthRadius);
    double newCircumference = earth.getCircumference() + addedLength;
    Circle newEarth(0);
    newEarth.setCircumference(newCircumference);
    return newEarth.getRadius() - earth.getRadius();
}

double calculateCost(double poolRadius, double pathWidth, double concreteCost, double fenceCost) {
    Circle pool(poolRadius);
    Circle outer(poolRadius + pathWidth);
    double pathArea = outer.getArea() - pool.getArea();
    double fenceLength = outer.getCircumference();
    return pathArea * concreteCost + fenceLength * fenceCost;
}