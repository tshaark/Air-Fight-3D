#include "main.h"

#ifndef PARACHUTE_H
#define PARACHUTE_H


class Parachute {
public:
    Parachute() {}
    Parachute(float x, float y, float z, color_t color, color_t color1, color_t color2);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    float xSpeed,ySpeed,zSpeed;
    void set_position(float x, float y, float z);
    void tick();
    double speed;
private:
    VAO *object[95];
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;
    VAO *object5;
    // VAO *object5;
};

#endif // BALL_H
