#include "aircraft.h"
#include "main.h"

Aircraft::Aircraft(float x, float y, float z,color_t color,color_t color1) {
    this->position = glm::vec3(x, y, z);
    this->rot= glm::mat4(1.0f);
    this->rotation.x = 0;
    this->rotation.y = 0;
    this->rotation.z = 0;


    int n=50;
    float r=0.3,r1=0.0,r2=0.5;
    GLfloat g_vertex_buffer_data0[9*n+9] ;
    for (int i = 0; i < n; ++i)
    {
        float angle = 2*M_PI*i/n;
        float angle2 = 2*M_PI*(i+1)/n;
        double x1=cos(angle);
        double y1=sin(angle);
        double x2=cos(angle2);
        double y2=sin(angle2);

        g_vertex_buffer_data0[9*i]=r*x1;
        g_vertex_buffer_data0[9*i+1]=r*y1;
        g_vertex_buffer_data0[9*i+2]=0;
        g_vertex_buffer_data0[9*i+3]=r2*x1;
        g_vertex_buffer_data0[9*i+4]=r2*y1;
        g_vertex_buffer_data0[9*i+5]=-0.5;
        g_vertex_buffer_data0[9*i+6]=r2*x2;
        g_vertex_buffer_data0[9*i+7]=r2*y2;
        g_vertex_buffer_data0[9*i+8]=-0.5;
    } 
    this->object0 = create3DObject(GL_TRIANGLES, n*3, g_vertex_buffer_data0, color1, GL_FILL);
    GLfloat g_vertex_buffer_data01[9*n+9] ;
    
   
    for (int i = 0; i < n; ++i)
    {
        float angle = 2*M_PI*i/n;
        float angle2 = 2*M_PI*(i+1)/n;
        double x1=cos(angle);
        double y1=sin(angle);
        double x2=cos(angle2);
        double y2=sin(angle2);

        g_vertex_buffer_data01[9*i]=r2*x2;
        g_vertex_buffer_data01[9*i+1]=r2*y2;
        g_vertex_buffer_data01[9*i+2]=-0.5;
        g_vertex_buffer_data01[9*i+3]=r*x1;
        g_vertex_buffer_data01[9*i+4]=r*y1;
        g_vertex_buffer_data01[9*i+5]=0.0f;
        g_vertex_buffer_data01[9*i+6]=r*x2;
        g_vertex_buffer_data01[9*i+7]=r*y2;
        g_vertex_buffer_data01[9*i+8]=0.0f;
    } 
    this->object01 = create3DObject(GL_TRIANGLES, n*3, g_vertex_buffer_data01, color1, GL_FILL);



    GLfloat g_vertex_buffer_data[9*n+9] ;
    
   
    for (int i = 0; i < n; ++i)
    {
        float angle = 2*M_PI*i/n;
        float angle2 = 2*M_PI*(i+1)/n;
        double x1=cos(angle);
        double y1=sin(angle);
        double x2=cos(angle2);
        double y2=sin(angle2);

        g_vertex_buffer_data[9*i]=r*x1;
        g_vertex_buffer_data[9*i+1]=r*y1;
        g_vertex_buffer_data[9*i+2]=2;
        g_vertex_buffer_data[9*i+3]=r*x1;
        g_vertex_buffer_data[9*i+4]=r*y1;
        g_vertex_buffer_data[9*i+5]=0.0f;
        g_vertex_buffer_data[9*i+6]=r*x2;
        g_vertex_buffer_data[9*i+7]=r*y2;
        g_vertex_buffer_data[9*i+8]=0.0f;
    } 
    this->object1 = create3DObject(GL_TRIANGLES, n*3, g_vertex_buffer_data, color, GL_FILL);


    GLfloat g_vertex_buffer_data1[9*n+9] ;
    for (int i = 0; i < n; ++i)
    {
        float angle = 2*M_PI*i/n;
        float angle2 = 2*M_PI*(i+1)/n;
        double x1=cos(angle);
        double y1=sin(angle);
        double x2=cos(angle2);
        double y2=sin(angle2);

        g_vertex_buffer_data1[9*i]=r*x2;
        g_vertex_buffer_data1[9*i+1]=r*y2;
        g_vertex_buffer_data1[9*i+2]=0.0f;
        g_vertex_buffer_data1[9*i+3]=r*x1;
        g_vertex_buffer_data1[9*i+4]=r*y1;
        g_vertex_buffer_data1[9*i+5]=2;
        g_vertex_buffer_data1[9*i+6]=r*x2;
        g_vertex_buffer_data1[9*i+7]=r*y2;
        g_vertex_buffer_data1[9*i+8]=2;
    } 

    this->object2 = create3DObject(GL_TRIANGLES, n*3, g_vertex_buffer_data1, color, GL_FILL);

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
        g_vertex_buffer_data2[9*i+2]=2.5;
        g_vertex_buffer_data2[9*i+3]=r*x1;
        g_vertex_buffer_data2[9*i+4]=r*y1;
        g_vertex_buffer_data2[9*i+5]=2;
        g_vertex_buffer_data2[9*i+6]=r*x2;
        g_vertex_buffer_data2[9*i+7]=r*y2;
        g_vertex_buffer_data2[9*i+8]=2;
    } 

    this->object3 = create3DObject(GL_TRIANGLES, n*3, g_vertex_buffer_data2, color1, GL_FILL);
    GLfloat g_vertex_buffer_data3[9*n+9] ;
    for (int i = 0; i < n; ++i)
    {
        float angle = 2*M_PI*i/n;
        float angle2 = 2*M_PI*(i+1)/n;
        double x1=cos(angle);
        double y1=sin(angle);
        double x2=cos(angle2);
        double y2=sin(angle2);
        g_vertex_buffer_data3[9*i]=r*x1;
        g_vertex_buffer_data3[9*i+1]=r*y1;
        g_vertex_buffer_data3[9*i+2]=2;
        g_vertex_buffer_data3[9*i+3]=r1*x1;
        g_vertex_buffer_data3[9*i+4]=r1*y1;
        g_vertex_buffer_data3[9*i+5]=2.5;
        g_vertex_buffer_data3[9*i+6]=r1*x2;
        g_vertex_buffer_data3[9*i+7]=r1*y2;
        g_vertex_buffer_data3[9*i+8]=2.5;
    } 

    this->object4 = create3DObject(GL_TRIANGLES, n*3, g_vertex_buffer_data3, color1, GL_FILL);


     static const GLfloat vertex_buffer_data[] = {
            0.0f,0.3f,0.25f,
            0.0f,0.3f,1.0f,
            2.0f,0.1f,0.25f,

            2.0f,0.1f,0.25f,
            0.0f,0.0f,0.25f,
            0.0f,0.0f,1.0f,

            0.0f,0.3f,0.25f,
            0.0f,0.0f,0.25f,
            2.0f,0.1f,0.25f,

            0.0f,0.3f,1.0f,
            0.0f,0.0f,1.0f,
            2.0f,0.1f,0.25f,

            0.0f,0.3f,0.25f,
            0.0f,0.3f,1.0f,
            -2.0f,0.1f,0.25f,

            -2.0f,0.1f,0.25f,
            0.0f,0.0f,0.25f,
            0.0f,0.0f,1.0f, 

            0.0f,0.3f,0.25f,
            0.0f,0.0f,0.25f,
            -2.0f,0.1f,0.25f,

            0.0f,0.3f,1.0f,
            0.0f,0.0f,1.0f,
            -2.0f,0.1f,0.25f,           

     };
    this->object5 = create3DObject(GL_TRIANGLES, 8*3, vertex_buffer_data, color, GL_FILL);

   
}

void Aircraft::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 xrot    = glm::rotate((float) (this->rotation.x * M_PI / 180.0f), glm::vec3(1, 0, 0));
    glm::mat4 yrot    = glm::rotate((float) (this->rotation.y * M_PI / 180.0f), glm::vec3(0, 1, 0));
    glm::mat4 zrot    = glm::rotate((float) (this->rotation.z * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    this->rot *= (yrot*xrot*zrot);
    Matrices.model *= (translate*this->rot);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
    draw3DObject(this->object4);
    draw3DObject(this->object0);
    draw3DObject(this->object01);
    draw3DObject(this->object5);
    this->rotation.x=0;
    this->rotation.y=0;
    this->rotation.z=0;
}

void Aircraft::set_position(float x, float y, float z) {
    // this->position = glm::vec3(x, y, -4);
}

void Aircraft::tick() {
    
}

