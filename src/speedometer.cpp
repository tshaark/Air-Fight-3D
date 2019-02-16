#include "speedometer.h"
#include "main.h"

Speedometer::Speedometer(float x, float y, float z,color_t color,color_t color1) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0.0;

    int n=50;
    float r1=0.6,r2=0.5;
    GLfloat g_vertex_buffer_data1[9*n+9] ;
    for (int i = 0; i < n; ++i)
    {
        float angle = 2*M_PI*i/n;
        float angle2 = 2*M_PI*(i+1)/n;
        double x1=cos(angle);
        double y1=sin(angle);
        double x2=cos(angle2);
        double y2=sin(angle2);

        g_vertex_buffer_data1[9*i]=0.0f;
        g_vertex_buffer_data1[9*i+1]=0.0f;
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

        g_vertex_buffer_data2[9*i]=0.0f;
        g_vertex_buffer_data2[9*i+1]=0.0f;
        g_vertex_buffer_data2[9*i+2]=0.0f;
        g_vertex_buffer_data2[9*i+3]=r2*x1;
        g_vertex_buffer_data2[9*i+4]=r2*y1;
        g_vertex_buffer_data2[9*i+5]=0.0f;
        g_vertex_buffer_data2[9*i+6]=r2*x2;
        g_vertex_buffer_data2[9*i+7]=r2*y2;
        g_vertex_buffer_data2[9*i+8]=0.0f;
    } 
    this->object2 = create3DObject(GL_TRIANGLES, n*3, g_vertex_buffer_data2, color1, GL_FILL);  


     static const GLfloat vertex_buffer_data[] = {
            -0.5f,0.0f,0.0f,
            0.0f,0.02f,0.0f,
            0.0f,-0.02f,0.0f,
     };
    this->object3 = create3DObject(GL_TRIANGLES, 1*3, vertex_buffer_data, color, GL_FILL);
}

void Speedometer::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    Matrices.model *= (translate*rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object3);

}

void Speedometer::set_position(float x, float y, float z) {
    // this->position = glm::vec3(x, y, -4);
}

void Speedometer::tick(float fact) {
    this->rotation=-10*fact;
}

