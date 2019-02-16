#include "main.h"

#ifndef FUEL_H
#define FUEL_H


class Fuel {
public:
    Fuel() {}
    Fuel(float x, float y, float z, color_t color,color_t color1);
    glm::vec3 position,rotation;
    void draw(glm::mat4 VP);
    glm:: mat4 rot;
    void set_position(float x, float y, float z);
    void tick();
    double speed;
private:
    VAO *object1;
    VAO *object2;
};

#endif // BALL_H
