//
// Created by Adam on 9/13/2020.
//

#ifndef UNTITLED_RAY_H
#define UNTITLED_RAY_H
#include "Definitions.h"


//It has two instances of Vertex, which are the ray’s starting point and endpoint.
//You can put the vertices into a vertex list and use references tothese points inRay.
//Ray contains a reference to the triangle on which the end point is located.
//The ray color is aColorDbl.
class Ray {
private:
    Vertex startPoint;
    Vertex endPoint;
    ColorDbl color;
    Direction dir;

public:

    Ray();

    ~Ray();


    //TODO: add reference to the triangle which the end point is located

    Ray(Vertex _startPoint, Vertex _endPoint) {
        startPoint = _startPoint;
        endPoint = _endPoint;
        dir = (glm::dvec3)endPoint - (glm::dvec3)startPoint;
    }

    Direction getDir();

    Vertex getStart(){
        return startPoint;
    }
};


#endif //UNTITLED_RAY_H
