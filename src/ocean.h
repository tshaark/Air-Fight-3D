#include "main.h"

#ifndef OCEAN_H
#define OCEAN_H


class Ocean {
public:
    Ocean() {}
    Ocean(float x, float y, float z, color_t color);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
private:
    VAO *object;
};

#endif // BALL_H