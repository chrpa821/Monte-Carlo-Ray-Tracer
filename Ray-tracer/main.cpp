#include <iostream>
#include "Camera.h"
#include <list>

int main() {
    std::cout << "Hello, World Test!" << std::endl;

    Camera camera;
    camera.render();
    camera.createImage();
    return 0;
}