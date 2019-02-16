#include "main.h"

#ifndef ALTBAR_H
#define ALTBAR_H


class Altbar {
public:
    Altbar() {}
    Altbar(float x, float y, float z, color_t color,color_t color1);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
private:
    VAO *object1;
    VAO *object2;
};

#endif // BALL_H
