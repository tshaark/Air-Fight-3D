#include "main.h"

#ifndef CANNON_H
#define CANNON_H


class Cannon {
public:
    Cannon() {}
    Cannon(float x, float y, float z, color_t color,glm::vec3 v);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    float xSpeed,ySpeed,zSpeed;
    void set_position(float x, float y, float z);
    void tick();
    int flag;
    double speed;
private:
    VAO *object[360];
    // VAO *object4;
    // VAO *object5;
};

#endif // BALL_H
