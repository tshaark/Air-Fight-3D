#include "main.h"

#ifndef AIRCRAFT_H
#define AIRCRAFT_H


class Aircraft {
public:
    Aircraft() {}
    Aircraft(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;
    VAO *object0;
    VAO *object01;
    VAO *object5;
};

#endif // BALL_H
