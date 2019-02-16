#include "radiotower.h"
#include "main.h"

Radiotower::Radiotower(float x, float y, float z,color_t color,color_t color1) {
    this->position = glm::vec3(x, y, z);


    int n=50;
    float r1=6.0,r2=6.0,r3=10.0,r4=6.0;
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
        g_vertex_buffer_data1[9*i+1]=20.0f;
        g_vertex_buffer_data1[9*i+2]=r2*y2;
        g_vertex_buffer_data1[9*i+3]=r1*x1;
        g_vertex_buffer_data1[9*i+4]=0.0f;
        g_vertex_buffer_data1[9*i+5]=r1*y1;
        g_vertex_buffer_data1[9*i+6]=r1*x2;
        g_vertex_buffer_data1[9*i+7]=0.0f;
        g_vertex_buffer_data1[9*i+8]=r1*y2;
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
        g_vertex_buffer_data2[9*i+1]=0.0f;
        g_vertex_buffer_data2[9*i+2]=r1*y1;
        g_vertex_buffer_data2[9*i+3]=r2*x1;
        g_vertex_buffer_data2[9*i+4]=20.0f;
        g_vertex_buffer_data2[9*i+5]=r2*y1;
        g_vertex_buffer_data2[9*i+6]=r2*x2;
        g_vertex_buffer_data2[9*i+7]=20.0f;
        g_vertex_buffer_data2[9*i+8]=r2*y2;
    } 
    this->object2 = create3DObject(GL_TRIANGLES, n*3, g_vertex_buffer_data2, color, GL_FILL);
    GLfloat g_vertex_buffer_data3[9*n+9] ;
    for (int i = 0; i < n; ++i)
    {
        float angle = 2*M_PI*i/n;
        float angle2 = 2*M_PI*(i+1)/n;
        double x1=cos(angle);
        double y1=sin(angle);
        double x2=cos(angle2);
        double y2=sin(angle2);

        g_vertex_buffer_data3[9*i]=r3*x2;
        g_vertex_buffer_data3[9*i+1]=25.0f;
        g_vertex_buffer_data3[9*i+2]=r3*y2;
        g_vertex_buffer_data3[9*i+3]=r2*x1;
        g_vertex_buffer_data3[9*i+4]=20.0f;
        g_vertex_buffer_data3[9*i+5]=r2*y1;
        g_vertex_buffer_data3[9*i+6]=r2*x2;
        g_vertex_buffer_data3[9*i+7]=20.0f;
        g_vertex_buffer_data3[9*i+8]=r2*y2;
    } 
    this->object3 = create3DObject(GL_TRIANGLES, n*3, g_vertex_buffer_data3, color1, GL_FILL);
    GLfloat g_vertex_buffer_data4[9*n+9] ;
    for (int i = 0; i < n; ++i)
    {
        float angle = 2*M_PI*i/n;
        float angle2 = 2*M_PI*(i+1)/n;
        double x1=cos(angle);
        double y1=sin(angle);
        double x2=cos(angle2);
        double y2=sin(angle2);

        g_vertex_buffer_data4[9*i]=r2*x1;
        g_vertex_buffer_data4[9*i+1]=20.0f;
        g_vertex_buffer_data4[9*i+2]=r2*y1;
        g_vertex_buffer_data4[9*i+3]=r3*x1;
        g_vertex_buffer_data4[9*i+4]=25.0f;
        g_vertex_buffer_data4[9*i+5]=r3*y1;
        g_vertex_buffer_data4[9*i+6]=r3*x2;
        g_vertex_buffer_data4[9*i+7]=25.0f;
        g_vertex_buffer_data4[9*i+8]=r3*y2;
    } 
    this->object4 = create3DObject(GL_TRIANGLES, n*3, g_vertex_buffer_data4, color1, GL_FILL); 

    GLfloat g_vertex_buffer_data5[9*n+9] ;
    for (int i = 0; i < n; ++i)
    {
        float angle = 2*M_PI*i/n;
        float angle2 = 2*M_PI*(i+1)/n;
        double x1=cos(angle);
        double y1=sin(angle);
        double x2=cos(angle2);
        double y2=sin(angle2);

        g_vertex_buffer_data5[9*i]=r4*x1;
        g_vertex_buffer_data5[9*i+1]=30.0f;
        g_vertex_buffer_data5[9*i+2]=r4*y1;
        g_vertex_buffer_data5[9*i+3]=r3*x1;
        g_vertex_buffer_data5[9*i+4]=25.0f;
        g_vertex_buffer_data5[9*i+5]=r3*y1;
        g_vertex_buffer_data5[9*i+6]=r3*x2;
        g_vertex_buffer_data5[9*i+7]=25.0f;
        g_vertex_buffer_data5[9*i+8]=r3*y2;
    } 
    this->object5 = create3DObject(GL_TRIANGLES, n*3, g_vertex_buffer_data5, color1, GL_FILL);

    GLfloat g_vertex_buffer_data6[9*n+9] ;
    for (int i = 0; i < n; ++i)
    {
        float angle = 2*M_PI*i/n;
        float angle2 = 2*M_PI*(i+1)/n;
        double x1=cos(angle);
        double y1=sin(angle);
        double x2=cos(angle2);
        double y2=sin(angle2);

        g_vertex_buffer_data6[9*i]=r3*x2;
        g_vertex_buffer_data6[9*i+1]=25.0f;
        g_vertex_buffer_data6[9*i+2]=r3*y2;
        g_vertex_buffer_data6[9*i+3]=r4*x1;
        g_vertex_buffer_data6[9*i+4]=30.0f;
        g_vertex_buffer_data6[9*i+5]=r4*y1;
        g_vertex_buffer_data6[9*i+6]=r4*x2;
        g_vertex_buffer_data6[9*i+7]=30.0f;
        g_vertex_buffer_data6[9*i+8]=r4*y2;
    } 
    this->object6 = create3DObject(GL_TRIANGLES, n*3, g_vertex_buffer_data6, color1, GL_FILL); 

   
}

void Radiotower::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
    draw3DObject(this->object4);
    draw3DObject(this->object5);
    draw3DObject(this->object6);
}

void Radiotower::set_position(float x, float y, float z) {
    // this->position = glm::vec3(x, y, -4);
}

void Radiotower::tick() {
// lite abhi
}

