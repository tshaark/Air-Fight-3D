#include "compass.h"
#include "main.h"

Compass::Compass(float x, float y, float z,color_t color,color_t color1) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0.0;

     static const GLfloat vertex_buffer_data1[] = {
            0.1f,0.0f,0.0f,
            0.0f,0.5f,0.0f,
            -0.1f,0.0f,0.0f,
     };
    this->object1 = create3DObject(GL_TRIANGLES, 1*3, vertex_buffer_data1, color, GL_FILL);

    static const GLfloat vertex_buffer_data2[] = {
            0.1f,0.0f,0.0f,
            0.0f,-0.5f,0.0f,
            -0.1f,0.0f,0.0f,
     };
    this->object2 = create3DObject(GL_TRIANGLES, 1*3, vertex_buffer_data2, color1, GL_FILL);
}

void Compass::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    Matrices.model *= (translate*rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
}

void Compass::set_position(float x, float y, float z) {
    // this->position = glm::vec3(x, y, -4);
}

void Compass::tick() {
    // this->rotation=fact;
}

