#include "petrol.h"
#include "main.h"

Petrol::Petrol(float x, float y, float z,color_t color) {
    this->position = glm::vec3(x, y, z);


    int n=50;
    float r=1.0;
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
        g_vertex_buffer_data1[9*i+1]=-1.5f;
        g_vertex_buffer_data1[9*i+2]=0.0f;
        g_vertex_buffer_data1[9*i+3]=r*x1;
        g_vertex_buffer_data1[9*i+4]=-1.5f;
        g_vertex_buffer_data1[9*i+5]=r*y1;
        g_vertex_buffer_data1[9*i+6]=r*x2;
        g_vertex_buffer_data1[9*i+7]=-1.5f;
        g_vertex_buffer_data1[9*i+8]=r*y2;
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

        g_vertex_buffer_data2[9*i]=r*x1;
        g_vertex_buffer_data2[9*i+1]=1.5f;
        g_vertex_buffer_data2[9*i+2]=r*y1;
        g_vertex_buffer_data2[9*i+3]=r*x1;
        g_vertex_buffer_data2[9*i+4]=-1.5f;
        g_vertex_buffer_data2[9*i+5]=r*y1;
        g_vertex_buffer_data2[9*i+6]=r*x2;
        g_vertex_buffer_data2[9*i+7]=-1.5f;
        g_vertex_buffer_data2[9*i+8]=r*y2;
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

        g_vertex_buffer_data3[9*i]=r*x2;
        g_vertex_buffer_data3[9*i+1]=-1.5f;
        g_vertex_buffer_data3[9*i+2]=r*y2;
        g_vertex_buffer_data3[9*i+3]=r*x1;
        g_vertex_buffer_data3[9*i+4]=1.5f;
        g_vertex_buffer_data3[9*i+5]=r*y1;
        g_vertex_buffer_data3[9*i+6]=r*x2;
        g_vertex_buffer_data3[9*i+7]=1.5f;
        g_vertex_buffer_data3[9*i+8]=r*y2;
    } 
    this->object3 = create3DObject(GL_TRIANGLES, n*3, g_vertex_buffer_data3, color, GL_FILL);
    GLfloat g_vertex_buffer_data4[9*n+9] ;
    for (int i = 0; i < n; ++i)
    {
        float angle = 2*M_PI*i/n;
        float angle2 = 2*M_PI*(i+1)/n;
        double x1=cos(angle);
        double y1=sin(angle);
        double x2=cos(angle2);
        double y2=sin(angle2);

        g_vertex_buffer_data4[9*i]=0.0f;
        g_vertex_buffer_data4[9*i+1]=1.5f;
        g_vertex_buffer_data4[9*i+2]=0.0f;
        g_vertex_buffer_data4[9*i+3]=r*x1;
        g_vertex_buffer_data4[9*i+4]=1.5f;
        g_vertex_buffer_data4[9*i+5]=r*y1;
        g_vertex_buffer_data4[9*i+6]=r*x2;
        g_vertex_buffer_data4[9*i+7]=1.5f;
        g_vertex_buffer_data4[9*i+8]=r*y2;
    } 
    this->object4 = create3DObject(GL_TRIANGLES, n*3, g_vertex_buffer_data4, color, GL_FILL); 
   
}

void Petrol::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
    draw3DObject(this->object4);
}

void Petrol::set_position(float x, float y, float z) {
    // this->position = glm::vec3(x, y, -4);
}

void Petrol::tick() {
    // abhi lite hai
}

