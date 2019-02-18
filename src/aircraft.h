#include "main.h"

#ifndef AIRCRAFT_H
#define AIRCRAFT_H


class Aircraft {
public:
    Aircraft() {}
    Aircraft(float x, float y, float z, color_t color,color_t color1);
    glm::vec3 position,rotation;
    void draw(glm::mat4 VP);
    glm:: mat4 rot;
    void set_position(float x, float y, float z);
    void tick();
    int flag;
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
