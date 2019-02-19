 #include "main.h"

#ifndef GPS_H
#define GPS_H


class Gps {
public:
    Gps() {}
    Gps(float x, float y, float z, color_t color,color_t color1);
    glm::vec3 position;
    glm::vec3 direction;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
    double speed;
private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;
    VAO *object5;
};

#endif // BALL_H
