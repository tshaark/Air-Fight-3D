#include "main.h"

#ifndef BOMB_H
#define BOMB_H


class Bomb {
public:
    Bomb() {}
    Bomb(float x, float y, float z, color_t color,glm::vec3 v);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    float xSpeed,ySpeed,zSpeed;
    void set_position(float x, float y, float z);
    void tick();
    double speed;
private:
    VAO *object[360];
    // VAO *object4;
    // VAO *object5;
};

#endif // BALL_H
