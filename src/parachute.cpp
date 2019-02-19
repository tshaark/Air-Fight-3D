#include "parachute.h"
#include "main.h"

Parachute::Parachute(float x, float y, float z,color_t color,color_t color1, color_t color2) {
    this->position = glm::vec3(x, y, z);
    this->xSpeed=0.0;
    this->ySpeed=0.0;
    this->zSpeed=0.0;
    float R=5.0;
    int k=0;
    for(int alpha = 0;alpha < 45; alpha++)
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
            g_vertex_buffer_data1[9*i+1]=a2;
            g_vertex_buffer_data1[9*i+2]=r2*y2;
            g_vertex_buffer_data1[9*i+3]=r1*x1;
            g_vertex_buffer_data1[9*i+4]=a1;
            g_vertex_buffer_data1[9*i+5]=r1*y1;
            g_vertex_buffer_data1[9*i+6]=r1*x2;
            g_vertex_buffer_data1[9*i+7]=a1;
            g_vertex_buffer_data1[9*i+8]=r1*y2;
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
            g_vertex_buffer_data2[9*i+1]=a1;
            g_vertex_buffer_data2[9*i+2]=r1*y1;
            g_vertex_buffer_data2[9*i+3]=r2*x1;
            g_vertex_buffer_data2[9*i+4]=a2;
            g_vertex_buffer_data2[9*i+5]=r2*y1;
            g_vertex_buffer_data2[9*i+6]=r2*x2;
            g_vertex_buffer_data2[9*i+7]=a2;
            g_vertex_buffer_data2[9*i+8]=r2*y2;
        } 
        this->object[k++] = create3DObject(GL_TRIANGLES, n*3, g_vertex_buffer_data2, color, GL_FILL);        
    }


     static const GLfloat vertex_buffer_data[] = {
            4.0f,0.0f,0.0f,
            4.3f,0.0f,0.0f,
            0.0f,-10.0f,0.0f,

            -4.0f,0.0f,0.0f,
            -4.3f,0.0f,0.0f,
            0.0f,-10.0f,0.0f,

            0.0f,0.0f,-4.0f,
            0.0f,0.0f,-4.3f,
            0.0f,-10.0f,0.0f,

            0.0f,0.0f,4.0f,
            0.0f,0.0f,4.3f,
            0.0f,-10.0f,0.0f,

     };
    this->object1 = create3DObject(GL_TRIANGLES, 4*3, vertex_buffer_data, color1, GL_FILL);

      int n=50;
      float  r1=1.0,r2=1.0;
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
            g_vertex_buffer_data1[9*i+1]=-13.0;
            g_vertex_buffer_data1[9*i+2]=r2*y2;
            g_vertex_buffer_data1[9*i+3]=r1*x1;
            g_vertex_buffer_data1[9*i+4]=-10.0;
            g_vertex_buffer_data1[9*i+5]=r1*y1;
            g_vertex_buffer_data1[9*i+6]=r1*x2;
            g_vertex_buffer_data1[9*i+7]=-10.0;
            g_vertex_buffer_data1[9*i+8]=r1*y2;
        } 
        this->object2 = create3DObject(GL_TRIANGLES, n*3, g_vertex_buffer_data1, color2, GL_FILL);
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
            g_vertex_buffer_data2[9*i+1]=-10.0;
            g_vertex_buffer_data2[9*i+2]=r1*y1;
            g_vertex_buffer_data2[9*i+3]=r2*x1;
            g_vertex_buffer_data2[9*i+4]=-13.0;
            g_vertex_buffer_data2[9*i+5]=r2*y1;
            g_vertex_buffer_data2[9*i+6]=r2*x2;
            g_vertex_buffer_data2[9*i+7]=-13.0;
            g_vertex_buffer_data2[9*i+8]=r2*y2;
        } 
        this->object3 = create3DObject(GL_TRIANGLES, n*3, g_vertex_buffer_data2, color2, GL_FILL); 


        GLfloat g_vertex_buffer_data3[9*n+9] ;
        for (int i = 0; i < n; ++i)
        {
            float angle = 2*M_PI*i/n;
            float angle2 = 2*M_PI*(i+1)/n;
            double x1=cos(angle);
            double y1=sin(angle);
            double x2=cos(angle2);
            double y2=sin(angle2);
            g_vertex_buffer_data3[9*i]=0.0;
            g_vertex_buffer_data3[9*i+1]=-13.0;
            g_vertex_buffer_data3[9*i+2]=0.0;
            g_vertex_buffer_data3[9*i+3]=r1*x1;
            g_vertex_buffer_data3[9*i+4]=-10.0;
            g_vertex_buffer_data3[9*i+5]=r1*y1;
            g_vertex_buffer_data3[9*i+6]=r1*x2;
            g_vertex_buffer_data3[9*i+7]=-10.0;
            g_vertex_buffer_data3[9*i+8]=r1*y2;
        } 
        this->object4 = create3DObject(GL_TRIANGLES, n*3, g_vertex_buffer_data3, color2, GL_FILL);
        GLfloat g_vertex_buffer_data4[9*n+9] ;
        for (int i = 0; i < n; ++i)
        {
            float angle = 2*M_PI*i/n;
            float angle2 = 2*M_PI*(i+1)/n;
            double x1=cos(angle);
            double y1=sin(angle);
            double x2=cos(angle2);
            double y2=sin(angle2);
            g_vertex_buffer_data4[9*i]=0.0;
            g_vertex_buffer_data4[9*i+1]=-10.0;
            g_vertex_buffer_data4[9*i+2]=0.0;
            g_vertex_buffer_data4[9*i+3]=r2*x1;
            g_vertex_buffer_data4[9*i+4]=-13.0;
            g_vertex_buffer_data4[9*i+5]=r2*y1;
            g_vertex_buffer_data4[9*i+6]=r2*x2;
            g_vertex_buffer_data4[9*i+7]=-13.0;
            g_vertex_buffer_data4[9*i+8]=r2*y2;
        } 
        this->object5 = create3DObject(GL_TRIANGLES, n*3, g_vertex_buffer_data4, color2, GL_FILL); 


}

void Parachute::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    for(int i=0;i<90;i++)
        draw3DObject(this->object[i]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
    draw3DObject(this->object4);
    draw3DObject(this->object5);  
}

void Parachute::set_position(float x, float y, float z) {
    // this->position = glm::vec3(x, y, -4);
}

void Parachute::tick() {
    this->ySpeed+=0.1*0.1633;
    this->position.y-=0.001*this->ySpeed;

}

