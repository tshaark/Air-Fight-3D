#include "ring.h"
#include "main.h"

Ring::Ring(float x, float y, float z,color_t color,color_t color1) {
    this->position = glm::vec3(x, y, z);


    int n=50;
    float r1=4.0,r2=3.0;
    GLfloat g_vertex_buffer_data1[9*n+9] ;
    for (int i = 0; i < n; ++i)
    {
        float angle = 2*M_PI*i/n;
        float angle2 = 2*M_PI*(i+1)/n;
        double x1=cos(angle);
        double y1=sin(angle);
        double x2=cos(angle2);
        double y2=sin(angle2);

        g_vertex_buffer_data1[9*i]=r2*x2;
        g_vertex_buffer_data1[9*i+1]=r2*y2;
        g_vertex_buffer_data1[9*i+2]=0.0f;
        g_vertex_buffer_data1[9*i+3]=r1*x1;
        g_vertex_buffer_data1[9*i+4]=r1*y1;
        g_vertex_buffer_data1[9*i+5]=0.0f;
        g_vertex_buffer_data1[9*i+6]=r1*x2;
        g_vertex_buffer_data1[9*i+7]=r1*y2;
        g_vertex_buffer_data1[9*i+8]=0.0f;
    } 
    this->object1 = create3DObject(GL_TRIANGLES, n*3, g_vertex_buffer_data1, color, GL_FILL);

    GLfloat g_vertex_buffer_data2[9*n+9] ;
    for (int i = 0; i < n; ++i)
    {
        float angle = 2*M_PI*i/n;
        float angle2 = 2*M_PI*(i+1)/n;
        double x1=cos(angle);
        double y1=sin(angle);
        double x2=cos(angle2);
        double y2=sin(angle2);

        g_vertex_buffer_data2[9*i]=r1*x1;
        g_vertex_buffer_data2[9*i+1]=r1*y1;
        g_vertex_buffer_data2[9*i+2]=0.0f;
        g_vertex_buffer_data2[9*i+3]=r2*x1;
        g_vertex_buffer_data2[9*i+4]=r2*y1;
        g_vertex_buffer_data2[9*i+5]=0.0f;
        g_vertex_buffer_data2[9*i+6]=r2*x2;
        g_vertex_buffer_data2[9*i+7]=r2*y2;
        g_vertex_buffer_data2[9*i+8]=0.0f;
    } 
    this->object2 = create3DObject(GL_TRIANGLES, n*3, g_vertex_buffer_data2, color1, GL_FILL);   
}

void Ring::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);

}

void Ring::set_position(float x, float y, float z) {
    // this->position = glm::vec3(x, y, -4);
}

void Ring::tick() {
// lite abhi
}

