#include "main.h"

#ifndef PETROL_H
#define PETROL_H


class Petrol {
public:
    Petrol() {}
    Petrol(float x, float y, float z, color_t color);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;
};

#endif // BALL_H
