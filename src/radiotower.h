#include "main.h"

#ifndef RADIOTOWER_H
#define RADIOTOWER_H


class Radiotower {
public:
    Radiotower() {}
    Radiotower(float x, float y, float z, color_t color,color_t color1);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    int flag;
    void tick();
private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;
    VAO *object5;
    VAO *object6;
};

#endif // BALL_H
