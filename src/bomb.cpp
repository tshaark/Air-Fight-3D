#include "bomb.h"
#include "main.h"

Bomb::Bomb(float x, float y, float z,color_t color) {
    this->position = glm::vec3(x, y, z);
    GLfloat base_vertex_buffer_data[15001];
    float radius=5.0;
    int ptr = 0;
    glm::vec3 end1(0,0,0);
    glm::vec3 end2(0,0,0);
    glm::vec3 end3(0,0,0);
    glm::vec3 end4(0,0,0);
    for(float alpha = 0;alpha < 181.0; alpha+=1){

        float c_radius = radius * sin(alpha * M_PI / 180.0);
        float d_radius = radius * sin((alpha+1) * M_PI / 180.0);

        int flag = 0;
        for(float theta = 0;theta < 361.0; theta += 100){
            end1 = glm::vec3(c_radius*cos(theta * M_PI / 180.0) , radius*cos(alpha * M_PI / 180.0), c_radius*sin(theta * M_PI / 180.0));
            end2 = glm::vec3(d_radius*cos(theta * M_PI / 180.0) , radius*cos((alpha+1)*M_PI/180.0), d_radius*sin(theta * M_PI / 180.0));
            end3 = glm::vec3(c_radius*cos((theta + 100) * M_PI / 180.0) , radius*cos(alpha * M_PI / 180.0), c_radius*sin((theta + 100) * M_PI / 180.0));
            end4 = glm::vec3(d_radius*cos((theta - 100) * M_PI / 180.0) , radius*cos((alpha+1)*M_PI/180.0), d_radius*sin((theta - 100) * M_PI / 180.0));
            base_vertex_buffer_data[ptr++] = end1.x;
            base_vertex_buffer_data[ptr++] = end1.y;
            base_vertex_buffer_data[ptr++] = end1.z;

            base_vertex_buffer_data[ptr++] = end2.x;
            base_vertex_buffer_data[ptr++] = end2.y;
            base_vertex_buffer_data[ptr++] = end2.z;

            if(flag % 2 != 0)
            {
                base_vertex_buffer_data[ptr++] = end3.x;
                base_vertex_buffer_data[ptr++] = end3.y;
                base_vertex_buffer_data[ptr++] = end3.z;
            }
            else
            {
                base_vertex_buffer_data[ptr++] = end4.x;
                base_vertex_buffer_data[ptr++] = end4.y;
                base_vertex_buffer_data[ptr++] = end4.z;
                theta -= 100;
            }
            flag++;
        }
    }
    this->object = create3DObject(GL_TRIANGLES, ptr/3, base_vertex_buffer_data,color);
}

void Bomb::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    // draw3DObject(this->object4);
    // draw3DObject(this->object5);  
}

void Bomb::set_position(float x, float y, float z) {
    // this->position = glm::vec3(x, y, -4);
}

void Bomb::tick() {
}

