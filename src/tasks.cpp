// Copyright 2022 UNN-CS
#include <cmath>
#include "tasks.h"
#include "circle.h"

double calculateRopeGap(double earthRadius) {
    Circle earth(earthRadius);
    double newFerence = earth.getFerence() + 1.0;
    earth.setFerence(newFerence);
    return earth.getRadius() - earthRadius;
}

double calculatePoolCost(double poolRadius, double pathWidth) {
    Circle pool(poolRadius);
    Circle path(poolRadius + pathWidth);

    double pathArea = path.getArea() - pool.getArea();
    double fenceLength = path.getFerence();

    double pathCost = pathArea * 1000;
    double fenceCost = fenceLength * 2000;

    return pathCost + fenceCost;
}