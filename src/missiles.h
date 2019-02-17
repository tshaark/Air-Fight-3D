#include "main.h"

#ifndef MISSILES_H
#define MISSILES_H


class Missiles {
public:
    Missiles() {}
    Missiles(float x, float y, float z, color_t color,color_t color1,glm::vec3 v);
    glm::vec3 position;
    float xSpeed,ySpeed,zSpeed;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
    double speed;
private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
    // VAO *object4;
    // VAO *object5;
};

#endif // BALL_H
