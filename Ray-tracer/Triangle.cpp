//
// Created by Chris Paulusson on 2020-09-13.
//

#include "Ray.h"
#include "Triangle.h"
#include "Definitions.h"
#include "glm/glm.hpp"

Triangle::Triangle() {}


Triangle::Triangle(Vertex _v0, Vertex _v1, Vertex _v2,  ColorDbl color) : v0(_v0), v1(_v1), v2(_v2), color(color) {
    normal = glm::normalize(glm::cross((glm::dvec3)v1 - (glm::dvec3)v0, (glm::dvec3)v2 - (glm::dvec3)v0));
}

Triangle::~Triangle() {}

bool Triangle::rayIntersection(Ray ray, Direction direction, Vertex &endPoint){
    glm::dvec3 edge1  = v1 - v0;
    glm::dvec3 edge2 = v2 - v0;
    glm::dvec3 pvec = glm::cross(direction, edge2);
    glm::dvec3 qvec = glm::cross(ray.getStart()-v0, edge1);
    glm::dvec3 tvec = ray.getStart()-v0;

    const double kEpsilon = 0.00001;

    double det = glm::dot(edge1, pvec);

    // if the determinant is negative the triangle is back-facing
    // if the determinant is close to 0, the ray misses the triangle
    if (det < kEpsilon) return false;

    // ray and triangle are parallel if det is close to 0
    if (fabs(det) < kEpsilon) return false;

    float invDet = 1 / det;

    //https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-rendering-a-triangle/moller-trumbore-ray-triangle-intersection
    double u = glm::dot(tvec, pvec) * invDet;
    if (u < 0 || u > 1) return false;

    double v = glm::dot(direction, qvec) * invDet;
    if (v < 0 || u + v > 1) return false;

    double t = glm::dot(edge2, qvec) * invDet;

    endPoint =  ray.getStart() + direction*t;

    return true;
}





