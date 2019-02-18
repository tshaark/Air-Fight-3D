#include "bomb.h"
#include "main.h"

Bomb::Bomb(float x, float y, float z,color_t color,glm::vec3 v) {
    this->position = glm::vec3(x, y, z);
    this->xSpeed=v.x;
    this->ySpeed=0.0;
    this->zSpeed=v.z;
    float R=0.4;
    int k=0;
    for(int alpha = 0;alpha < 180; alpha++)
    {
        int n=50;
        float r1=R*sin(alpha),r2=R*sin(alpha+1);
        float a1=R*cos(alpha),a2=R*cos(alpha+1);
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
            g_vertex_buffer_data1[9*i+2]=a2+0.0f;
            g_vertex_buffer_data1[9*i+3]=r1*x1;
            g_vertex_buffer_data1[9*i+4]=r1*y1;
            g_vertex_buffer_data1[9*i+5]=a1+0.0f;
            g_vertex_buffer_data1[9*i+6]=r1*x2;
            g_vertex_buffer_data1[9*i+7]=r1*y2;
            g_vertex_buffer_data1[9*i+8]=a1+0.0f;
        } 
        this->object[k++] = create3DObject(GL_TRIANGLES, n*3, g_vertex_buffer_data1, color, GL_FILL);
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
            g_vertex_buffer_data2[9*i+2]=a1+0.0f;
            g_vertex_buffer_data2[9*i+3]=r2*x1;
            g_vertex_buffer_data2[9*i+4]=r2*y1;
            g_vertex_buffer_data2[9*i+5]=a2+0.0f;
            g_vertex_buffer_data2[9*i+6]=r2*x2;
            g_vertex_buffer_data2[9*i+7]=r2*y2;
            g_vertex_buffer_data2[9*i+8]=a2+0.0f;
        } 
        this->object[k++] = create3DObject(GL_TRIANGLES, n*3, g_vertex_buffer_data2, color, GL_FILL);        
    }
}

void Bomb::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    for(int i=0;i<360;i++)
        draw3DObject(this->object[i]);
    // draw3DObject(this->object4);
    // draw3DObject(this->object5);  
}

void Bomb::set_position(float x, float y, float z) {
    // this->position = glm::vec3(x, y, -4);
}

void Bomb::tick() {
    this->ySpeed+=0.1633;
    this->position.x+=this->xSpeed;
    this->position.y-=this->ySpeed;
    this->position.z+=this->zSpeed;

}

