#include "missiles.h"
#include "main.h"

Missiles::Missiles(float x, float y, float z,color_t color,color_t color1,glm::vec3 v) {
    this->position = glm::vec3(x, y, z);
    this->xSpeed=v.x;
    this->ySpeed=v.y;
    this->zSpeed=v.z;
    int n=50;
    float r1=0.08,r2=0.0;
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
        g_vertex_buffer_data2[9*i+5]=-0.2f;
        g_vertex_buffer_data2[9*i+6]=r1*x2;
        g_vertex_buffer_data2[9*i+7]=r1*y2;
        g_vertex_buffer_data2[9*i+8]=-0.2f;
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
        g_vertex_buffer_data3[9*i+2]=-0.2;
        g_vertex_buffer_data3[9*i+3]=r1*x1;
        g_vertex_buffer_data3[9*i+4]=r1*y1;
        g_vertex_buffer_data3[9*i+5]=0.0f;
        g_vertex_buffer_data3[9*i+6]=r1*x2;
        g_vertex_buffer_data3[9*i+7]=r1*y2;
        g_vertex_buffer_data3[9*i+8]=0.0f;
    } 
    this->object3 = create3DObject(GL_TRIANGLES, n*3, g_vertex_buffer_data3, color, GL_FILL);
  
}

void Missiles::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
    // draw3DObject(this->object4);
    // draw3DObject(this->object5);  
}

void Missiles::set_position(float x, float y, float z) {
    // this->position = glm::vec3(x, y, -4);
}

void Missiles::tick() {
    this->position.x+=2*this->xSpeed;
    this->position.y+=2*this->ySpeed;
    this->position.z+=2*this->zSpeed;

    
}

