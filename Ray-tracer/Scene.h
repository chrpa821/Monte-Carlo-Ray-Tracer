//
// Created by Chris Paulusson on 2020-09-13.
//

#ifndef UNTITLED_SCENE_H
#define UNTITLED_SCENE_H
#define _USE_MATH_DEFINES

#include <list>
#include "Triangle.h"
#include <cmath>
#include "Definitions.h"
#include "Tetrahedron.h"
#include "Sphere.h"
#include <random>
#include <cmath>

//Scene contains instances of Triangle.  We use one Scene object that consists of 24
//instances of Triangle. Scene objects are closed. The triangles of the floor and the
//ceiling should be white.  Each of the 6walls has a different color.
//It should have a method that determines which triangle is intersected by the Ray arg by
//calling successively the rayIntersection(Ray arg) method of each Triangle.  It then passes references
//to the triangle and the intersection point to theRay arg.
class Scene {
private:
    Triangle triangleList[26];
    Tetrahedron tetrahedron;
    Sphere sphereList[10];

public:
    Scene();
    ~Scene();

    void CastRay(Ray &ray, int rayDepth);
    void createLocalCoordinateSystem(const Direction &N, Direction &Nt, Direction &Nb);
    Direction uniformSampleHemisphere(const float &r1, const float &r2);

    ColorDbl computeDirectLight(Ray &ray, bool orenNayar);
    ColorDbl computeIndirectLight(Ray &ray, int rayDepth);

    void russianRoulette(Ray &ray);

    Direction randomRay(Ray ray);
};

#endif //UNTITLED_SCENE_H
