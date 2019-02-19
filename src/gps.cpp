#include "gps.h"
#include "main.h"

Gps::Gps(float x, float y, float z,color_t color,color_t color1) {
    this->position = glm::vec3(x, y, z);
    int n=50;
    float r1=0.2,r2=0.4,r3=0.0;
    GLfloat g_vertex_buffer_data1[9*n+9] ;
    for (int i = 0; i < n; ++i)
    {
        float angle = 2*M_PI*i/n;
        float angle2 = 2*M_PI*(i+1)/n;
        double x1=cos(angle);
        double y1=sin(angle);
        double x2=cos(angle2);
        double y2=sin(angle2);

        g_vertex_buffer_data1[9*i]=0.0;
        g_vertex_buffer_data1[9*i+1]=0.0f;
        g_vertex_buffer_data1[9*i+2]=-0.2;
        g_vertex_buffer_data1[9*i+3]=r1*x1;
        g_vertex_buffer_data1[9*i+4]=r1*y1;
        g_vertex_buffer_data1[9*i+5]=-0.2;
        g_vertex_buffer_data1[9*i+6]=r1*x2;
        g_vertex_buffer_data1[9*i+7]=r1*y2;
        g_vertex_buffer_data1[9*i+8]=-0.2;
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

        g_vertex_buffer_data2[9*i]=r1*x2;
        g_vertex_buffer_data2[9*i+1]=r1*y2;
        g_vertex_buffer_data2[9*i+2]=0.0;
        g_vertex_buffer_data2[9*i+3]=r1*x1;
        g_vertex_buffer_data2[9*i+4]=r1*y1;
        g_vertex_buffer_data2[9*i+5]=-1.0f;
        g_vertex_buffer_data2[9*i+6]=r1*x2;
        g_vertex_buffer_data2[9*i+7]=r1*y2;
        g_vertex_buffer_data2[9*i+8]=-1.0f;
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

        g_vertex_buffer_data3[9*i]=r1*x2;
        g_vertex_buffer_data3[9*i+1]=r1*y2;
        g_vertex_buffer_data3[9*i+2]=-1.0;
        g_vertex_buffer_data3[9*i+3]=r1*x1;
        g_vertex_buffer_data3[9*i+4]=r1*y1;
        g_vertex_buffer_data3[9*i+5]=0.0f;
        g_vertex_buffer_data3[9*i+6]=r1*x2;
        g_vertex_buffer_data3[9*i+7]=r1*y2;
        g_vertex_buffer_data3[9*i+8]=0.0f;
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

        g_vertex_buffer_data4[9*i]=r3*x2;
        g_vertex_buffer_data4[9*i+1]=r3*y2;
        g_vertex_buffer_data4[9*i+2]=1.0;
        g_vertex_buffer_data4[9*i+3]=r2*x1;
        g_vertex_buffer_data4[9*i+4]=r2*y1;
        g_vertex_buffer_data4[9*i+5]=0.0f;
        g_vertex_buffer_data4[9*i+6]=r2*x2;
        g_vertex_buffer_data4[9*i+7]=r2*y2;
        g_vertex_buffer_data4[9*i+8]=0.0f;
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

        g_vertex_buffer_data5[9*i]=r2*x1;
        g_vertex_buffer_data5[9*i+1]=r2*y1;
        g_vertex_buffer_data5[9*i+2]=0.0;
        g_vertex_buffer_data5[9*i+3]=r3*x1;
        g_vertex_buffer_data5[9*i+4]=r3*y1;
        g_vertex_buffer_data5[9*i+5]=0.1f;
        g_vertex_buffer_data5[9*i+6]=r3*x2;
        g_vertex_buffer_data5[9*i+7]=r3*y2;
        g_vertex_buffer_data5[9*i+8]=0.1f;
    } 
    this->object5 = create3DObject(GL_TRIANGLES, n*3, g_vertex_buffer_data5, color1, GL_FILL);
  
}

void Gps::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position); 
    this->direction=glm::normalize(this->direction);
    glm::mat4 rotate = glm::mat4(1.0f);
    rotate[2][0]=this->direction.x;
    rotate[2][1]=this->direction.y;
    rotate[2][2]=this->direction.z;
    rotate[0][0]=this->direction.y;
    rotate[0][1]=-this->direction.x;
    rotate[0][2]=0.0;
    glm::vec3 v = glm::cross(this->direction,glm::vec3(this->direction.y,-this->direction.x,0));
    rotate[1][0]=v.x;
    rotate[1][1]=v.y;
    rotate[1][2]=v.z;
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate*rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
    draw3DObject(this->object4);
    draw3DObject(this->object5);
    // draw3DObject(this->object4);
    // draw3DObject(this->object5);  
}

void Gps::set_position(float x, float y, float z) {
    // this->position = glm::vec3(x, y, -4);
}

void Gps::tick() {

    
}

