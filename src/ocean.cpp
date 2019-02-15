#include "ocean.h"
#include "main.h"

Ocean::Ocean(float x, float y, float z,color_t color) {
    this->position = glm::vec3(x, y, z);


     static const GLfloat vertex_buffer_data[] = {
        2000.0f,0.0f,-2000.0f,
        -2000.0f,0.0f,-2000.0f,
        -2000.0f,0.0f,2000.0f,

        -2000.0f,0.0f,2000.0f,
        2000.0f,0.0f,2000.0f,
        2000.0f,0.0f,-2000.0f,
     };
    this->object = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data, color, GL_FILL);
    

   
}

void Ocean::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Ocean::set_position(float x, float y, float z) {
    // this->position = glm::vec3(x, y, -4);
}

void Ocean::tick() {
// lite abhi
}

