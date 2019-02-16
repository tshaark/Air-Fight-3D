#include "main.h"
#include "timer.h"
#include "aircraft.h"
#include "ocean.h"
#include "island.h"
#include "score.h"
#include "volcano.h"
#include "radiotower.h"
#include "fuel.h"
#include "ring.h"


using namespace std;

GLMatrices Matrices;
GLMatrices MatricesO;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

Aircraft plane;
Ocean sea;
Island landV[25];
Island landC[25];
int a[25],b[25],c[25],d[25];
Score s[4]; 
Volcano vol[25];
Radiotower tow[25];
Fuel gas;
Ring ring[32];

float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;
int camFlag=0,xA,xB,xC,tA,tB,tC;
float aX,aY,aZ;
float speedX,speedY,speedZ;
int score;
float fuel=100.0;

Timer t60(1.0 / 60);

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
   
    glm::vec3 eye = plane.position ;
    // cout<<plane.rotation.y<<endl;
    // glm::vec3 eye (xA,xB,xC);
    if(camFlag==0)
        eye = plane.position -glm::vec3(10*sin(aY*M_PI/180.0f),-4,10*cos(aY*M_PI/180.0f));
        // eye = plane.position +glm::vec3(-10*plane.rot[2][0]-10*plane.rot[1][0],5*plane.rot[2][1]+5*plane.rot[1][1],-10*plane.rot[2][2]-10*plane.rot[1][2]);
    else if(camFlag==1)
        eye = plane.position +glm::vec3(0,10,0);
    else if(camFlag==2)
        eye = plane.position -glm::vec3(0,0,-4);

    glm::vec3 target = plane.position;
    glm::vec3 target1 = plane.position + glm::vec3(0,0,6);

    // cout<<eye.x<<" "<<eye.y<<" "<<eye.z<<endl;

   
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
        glm::vec3 up(plane.rot[1][0], plane.rot[1][1], plane.rot[1][2]);
        glm::vec3 up1(0, 0, 1);
    if(camFlag == 0)
        Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    if(camFlag == 1)
        Matrices.view = glm::lookAt( eye, target, up1 ); // Rotating Camera for 3D
    if(camFlag == 2)
        Matrices.view = glm::lookAt( eye, target1, up ); // Rotating Camera for 3D
    // Compute Camera matrix (view)
    // if(camFlag ==0)
    MatricesO.view = glm::lookAt(glm::vec3(0,0,10),glm::vec3(0,0,0),glm::vec3(0,1,0));
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;
    glm::mat4 VPO = MatricesO.projection * MatricesO.view;


    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model
    int tens=1;

    // Scene render
    plane.draw(VP);
    sea.draw(VP);
    gas.draw(VPO,fuel/100.0f);
    for(int i=0;i<25;i++)
    {
        landV[i].draw(VP);
    }
    for(int i=0;i<32;i++)
    {
        ring[i].draw(VP);
    }
    for (int i = 0; i < 25; ++i)
    {
        vol[i].draw(VP);
    }
    for(int i=0;i<25;i++)
    {
        landC[i].draw(VP);
    }
    for(int i=0;i<25;i++)
    {
        tow[i].draw(VP);
    }
    for (int i = 0; i < 4; ++i)
    {
        s[i].draw(VPO,(score/tens)%10);
        tens*=10;
    } 
}

void tick_input(GLFWwindow *window) {
    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int up = glfwGetKey(window, GLFW_KEY_SPACE);
    int down = glfwGetKey(window, GLFW_KEY_C);
    int forward = glfwGetKey(window, GLFW_KEY_W);
    int yawLeft = glfwGetKey(window, GLFW_KEY_A);
    int yawRight = glfwGetKey(window, GLFW_KEY_D);
    int pitchDown = glfwGetKey(window, GLFW_KEY_UP);
    int pitchUp = glfwGetKey(window, GLFW_KEY_DOWN);
    int rotLeft = glfwGetKey(window, GLFW_KEY_Q);
    int rotRight = glfwGetKey(window, GLFW_KEY_E);
    int view = glfwGetKey(window, GLFW_KEY_V);
    int view1 = glfwGetKey(window, GLFW_KEY_B);
    int view2 = glfwGetKey(window, GLFW_KEY_N);


    if (up){
        plane.position.y+=0.5f;
    }
    if (down){
        plane.position.y-=0.5f;
    }
    if (forward){
        // speedX += (plane.rot[2][0]);
        // speedZ += (plane.rot[2][2]);
        plane.position.x += (plane.rot[2][0]);
        plane.position.z += (plane.rot[2][2]);
        plane.position.y += 0.8*(plane.rot[2][1]);
    }
    if (yawLeft){
        plane.rotation.y += 0.5;
        aY+= 0.5;
    }
    if (yawRight){
        plane.rotation.y -= 0.5;
        aY-= 0.5;
    }
    if (pitchDown){
        plane.rotation.x += 0.5;
    }
    if (pitchUp){
        plane.rotation.x -= 0.5;
    }
    if (rotLeft){
        plane.rotation.z -= 0.5;
    }
    if (rotRight){
        plane.rotation.z += 0.5;
    }
    if (view){
        camFlag=1;
    }
    if (view1){
        camFlag=2;
    }
    if (view2){
        camFlag=0;
    }
}

void tick_elements() {
    plane.tick();
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models
    int k=0;
    plane     = Aircraft(0, 40, 0, COLOR_GRAY, COLOR_BLACK);
    sea       = Ocean(0,0,0,COLOR_BLUE);
    gas       = Fuel(3.25,3.5,0.0,COLOR_RED,COLOR_LGREEN);
    for(int i=0;i<32;i++)
    {
        if(i%4==0)
            ring[i]      = Ring(rand()%500, 50,rand()%500,COLOR_RED,COLOR_BLACK);
        else if(i%4==1)
            ring[i]      = Ring(-rand()%500, 50,rand()%500,COLOR_RED,COLOR_BLACK);
        else if(i%4==2)
            ring[i]      = Ring(rand()%500, 50,-rand()%500,COLOR_RED,COLOR_BLACK);
        else if(i%4==3)
            ring[i]      = Ring(-rand()%500, 50,-rand()%500,COLOR_RED,COLOR_BLACK);

    }
    for (int i = 0; i < 25; ++i)
    {
        if(i%2==0)
        {
            a[i]=rand()%1000+i*50;
            b[i]=rand()%1000+i*60;
            c[i]=rand()%1000+i*70;
            d[i]=rand()%1000+i*80;
        }
        else
        {
            a[i]=(-1)*rand()%1000+i*50;
            b[i]=(-1)*rand()%1000+i*60;
            c[i]=(-1)*rand()%1000+i*70;
            d[i]=(-1)*rand()%1000+i*80;
        }
        landV[i] = Island(a[i],0.1,b[i],COLOR_CLAY);
        vol[i] = Volcano(a[i],0.1,b[i],COLOR_BROWN,COLOR_RED);
        landC[i]= Island(c[i],0.2,d[i],COLOR_GREEN);
        tow[i] = Radiotower(c[i],0.2,d[i],COLOR_BLACK,COLOR_GOLD);
    }
    for (int i = 0; i < 4; ++i)
    {
        s[i]=Score(-4.0+0.5*(4-i),3.5,COLOR_BLACK);
    }


    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 600;
    int height = 600;
  

    window = initGLFW(width, height);

    initGL (window, width, height);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            if(fuel>=0)
                fuel-=0.01;
            tick_elements();
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_input(window);
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}

void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::perspective(45.0f,1.0f,0.1f,1000.0f);
    MatricesO.projection = glm::ortho(left,right,bottom,top,0.1f,1000.0f);

}
