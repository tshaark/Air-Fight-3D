#include "fuel.h"
#include "main.h"

Fuel::Fuel(float x, float y, float z,color_t color,color_t color1) {
    this->position = glm::vec3(x, y, z);

     static const GLfloat vertex_buffer_data1[] = {
            0.5f,0.25f,0.0f,
            0.5f,-0.25f,0.0f,
            0.55f,-0.25f,0.0f,

            0.5f,0.25f,0.0f,
            0.55f,0.25f,0.0f,
            0.55f,-0.25f,0.0f,

            -0.5f,0.25f,0.0f,
            -0.5f,-0.25f,0.0f,
            -0.55f,-0.25f,0.0f,

            -0.5f,0.25f,0.0f,
            -0.55f,0.25f,0.0f,
            -0.55f,-0.25f,0.0f,

            -0.55f,0.3f,0.0f,
            0.55f,0.25f,0.0f,
            -0.55f,0.25f,0.0f,

            -0.55f,0.3f,0.0f ,
            0.55f,0.3f,0.0f,
            0.55f,0.25f,0.0f, 

            -0.55f,-0.3f,0.0f,
            0.55f,-0.25f,0.0f,
            -0.55f,-0.25f,0.0f,

            -0.55f,-0.3f,0.0f ,
            0.55f,-0.3f,0.0f,
            0.55f,-0.25f,0.0f,

            0.55f,0.1f,0.0f,
            0.55f,-0.1f,0.0f,
            0.65f,-0.1f,0.0f,

            0.55f,0.1f,0.0f,
            0.65f,0.1f,0.0f,
            0.65,-0.1f,0.0f,           

     };
    this->object1 = create3DObject(GL_TRIANGLES, 10*3, vertex_buffer_data1, color, GL_FILL);

    static const GLfloat vertex_buffer_data2[] = {
            -0.5f,0.25f,0.0f,
            0.5f,0.25f,0.0f,
            0.5f,-0.25f,0.0f,

            -0.5f,0.25f,0.0f,
            0.5f,-0.25f,0.0f,
            -0.5f,-0.25f,0.0f,
     };
    this->object2 = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data2, color1, GL_FILL);

   
}

void Fuel::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
}

void Fuel::set_position(float x, float y, float z) {
    // this->position = glm::vec3(x, y, -4);
}

void Fuel::tick() {
    
}

