#include "altbar.h"
#include "main.h"

Altbar::Altbar(float x, float y, float z,color_t color,color_t color1) {
    this->position = glm::vec3(x, y, z);

     static const GLfloat vertex_buffer_data[] = {
            -0.05f,0.5f,0.0f,
            0.05f,-0.5f,0.0f,
            0.05f,0.5f,0.0f,

            -0.05f,0.5f,0.0f,
            0.05f,-0.5f,0.0f,
            -0.05f,-0.5f,0.0f,
     };
    this->object1 = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data, color, GL_FILL);

    static const GLfloat vertex_buffer_data1[] = {
            -0.2f,0.05f,0.0f,
            0.2f,-0.05f,0.0f,
            0.2f,0.05f,0.0f,

            -0.2f,0.05f,0.0f,
            0.2f,-0.05f,0.0f,
            -0.2f,-0.05f,0.0f,
     };
    this->object2 = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data1, color1, GL_FILL);
}

void Altbar::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);

}

void Altbar::set_position(float x, float y, float z) {
    // this->position = glm::vec3(x, y, -4);
}

void Altbar::tick() {
}

