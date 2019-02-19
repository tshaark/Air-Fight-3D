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
#include "speedometer.h"
#include "altbar.h"
#include "compass.h"
#include "missiles.h"
#include "bomb.h"
#include "cannon.h"
#include "petrol.h"



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
Score life;
Volcano vol[25];
Radiotower tow[25];
Fuel gas;
Ring ring[32];
Speedometer meter;
Altbar bar;
Compass comp;
vector<Missiles> m;
vector<Bomb> bomb;
vector<Cannon> cannon;
Petrol p[12];

float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;
int camFlag=0,xA,xB,xC,tA,tB,tC;
float aX,aY,aZ;
float speedX,speedY,speedZ;
int score;
float fuel=100.0;
float fact;
int lives=5;
int rFlag[25];
int ringFlag[32];
int pFlag[12];


Timer t60(1.0 / 60);

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // cout<<plane.position.y<<endl;
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
    else if(camFlag==3)
        eye = plane.position +glm::vec3(10,4,0);

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
    if(camFlag == 3)
        Matrices.view = glm::lookAt( eye, target, up );
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
    meter.draw(VPO);
    comp.draw(VPO);
    bar.draw(VPO,plane.position.y);
    life.draw(VPO,lives);
    for(int i=0;i<12;i++)
    {
        if(!pFlag[i])
            p[i].draw(VP);
    }
    for(int i=0;i<25;i++)
    {
        landV[i].draw(VP);
    }
    for(int i=0;i<32;i++)
    {
        if(ringFlag[i])
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
        if(rFlag[i]>0)
            tow[i].draw(VP);
    }
    for (int i = 0; i < 4; ++i)
    {
        s[i].draw(VPO,(score/tens)%10);
        tens*=10;
    } 
    for(int i=0;i<m.size();i++)
    {
        m[i].draw(VP);
    }
    for(int i=0;i<bomb.size();i++)
    {
        bomb[i].draw(VP);
    }
    for(int i=0;i<cannon.size();i++)
    {
        cannon[i].draw(VP);
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
    int view3 = glfwGetKey(window, GLFW_KEY_M);
    int shoot = glfwGetKey(window, GLFW_KEY_ENTER);
    int boom  = glfwGetKey(window, GLFW_KEY_X);

    plane.position.x += fact*(plane.rot[2][0]);
    plane.position.z += fact*(plane.rot[2][2]);
    if(plane.position.y<=262.5)
        plane.position.y += fact*(plane.rot[2][1]);
    if (up){
        if(plane.position.y<=262.5)
            plane.position.y+=0.5f;
    }
    if (down){
        plane.position.y-=0.5f;
    }
    if (forward){
        fact += 0.05;
    }
    if (yawLeft){
        plane.rotation.y += 0.5;
        comp.rotation -= 0.5;
        aY+= 0.5;
    }
    if (yawRight){
        plane.rotation.y -= 0.5;
        comp.rotation += 0.5;  
        aY-= 0.5;
    }
    if(shoot)
    {
        m.push_back(Missiles(plane.position.x,plane.position.y,plane.position.z,COLOR_GOLD,COLOR_RED,glm::vec3(plane.rot[2][0],plane.rot[2][1],plane.rot[2][2])));
    }
    if(boom && plane.flag==0)
    {
        plane.flag=1;
        bomb.push_back(Bomb(plane.position.x,plane.position.y-2.0,plane.position.z,COLOR_CRIMSON,glm::vec3(plane.rot[2][0],plane.rot[2][1],plane.rot[2][2])));
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
        camFlag=3;
    }
    if (view3){
        camFlag=0;
    }
}

void tick_elements() {
    plane.tick();
    if(fact>0)
    fact-=0.03;
    meter.tick(fact); 
    for(int i=0;i<25;i++)
    {
        tow[i].tick();
    }
    for (int i = 0; i < m.size(); ++i)
    {
        m[i].tick();
    }
    for(int i=0;i<bomb.size();i++)
    {
        bomb[i].tick();
    }
    for(int i=0;i<cannon.size();i++)
    {
        cannon[i].tick();
    }
    float px=plane.position.x,py=plane.position.y,pz=plane.position.z;
    for(int i=0;i<25;i++)
    {
        if(rFlag[i]>0)
        {   
            float tx=tow[i].position.x,ty=tow[i].position.y,tz=tow[i].position.z;
            if(sqrt((px-tx)*(px-tx)+(pz-tz)*(pz-tz))<=100.0 && py-ty<=70.0  && tow[i].flag==0)
            {
                tow[i].flag=1;
                cannon.push_back(Cannon(tx,ty+30.0,tz,COLOR_BLACK,glm::normalize(glm::vec3(px-tx,py-ty-30.0,pz-tz))));
            }
        }
    }
    for(int i=0;i<12;i++)
    {
        float gx=p[i].position.x,gy=p[i].position.y,gz=p[i].position.z;
        if(sqrt((gx-px)*(gx-px)+(gy-py)*(gy-py)+(gz-pz)*(gz-pz))<=2.0)
        {   
            pFlag[i]=1;
            fuel=100.0;
            break;
        }

    }
    for(int i=0;i<cannon.size();i++)
    {
        float cx=cannon[i].position.x,cy=cannon[i].position.y,cz=cannon[i].position.z;
        if(sqrt((cx-px)*(cx-px)+(cy-py)*(cy-py)+(cz-pz)*(cz-pz))<=1.0)
        {
            lives--;
            if(lives<=0)
            {
                quit(window);
            }
        }
        if(sqrt((cx-px)*(cx-px)+(cy-py)*(cy-py)+(cz-pz)*(cz-pz))>=70.0)
        {
            cannon.erase(cannon.begin()-i);
            i--;
        }
    }
    if(py<=0.0)
        quit(window);
    for (int i = 0; i < m.size(); ++i)
    {
        if(sqrt((px-m[i].position.x)*(px-m[i].position.x)+(pz-m[i].position.z)*(pz-m[i].position.z))>= 300.0)
        {
            m.erase(m.begin()+i);
            i--;
        }
    }
    for(int i=0;i<bomb.size();i++)
    {
        if(bomb[i].position.y<=0)
        {
            bomb.erase(bomb.begin()+i);
            i--;
        }
    }
    for(int i=0;i<25;i++)
    {
        if(sqrt((px-vol[i].position.x)*(px-vol[i].position.x)+(pz-vol[i].position.z)*(pz-vol[i].position.z))<= 10.0 && (py-vol[i].position.y<=60.0))
        {
            quit(window);
        }
    }
    for(int i=0;i< m.size();i++)
    {
        for(int j=0;j<25;j++)
        {
            if(rFlag[j]>0)
            {
                float mx=m[i].position.x,my=m[i].position.y,mz=m[i].position.z;
                float tx=tow[j].position.x,ty=tow[j].position.y,tz=tow[j].position.z;
                if(sqrt((mx-tx)*(mx-tx)+(mz-tz)*(mz-tz))<= 30.0 && my-ty<=31.0 && my-ty>=0.0)
                {
                    rFlag[j]--;
                    m.erase(m.begin()+i);
                    i--;
                    score+=2;
                }
            }
        }
    }
    for(int i=0;i< bomb.size();i++)
    {
        for(int j=0;j<25;j++)
        {
            if(rFlag[j]>0)
            {
                float mx=bomb[i].position.x,my=bomb[i].position.y,mz=bomb[i].position.z;
                float tx=tow[j].position.x,ty=tow[j].position.y,tz=tow[j].position.z;
                if(bomb[i].position.y<=1.0 && sqrt((mx-tx)*(mx-tx)+(mz-tz)*(mz-tz))<= 50.0)
                {
                     rFlag[j]=0;
                    bomb.erase(bomb.begin()+i);
                    i--;
                    score+=50;
                }
            }
        }
    }
    for(int i=0;i<32;i++)
    {
        if(sqrt((px-ring[i].position.x)*(px-ring[i].position.x)+(py-ring[i].position.y)*(py-ring[i].position.y)+(pz-ring[i].position.z)*(pz-ring[i].position.z))<= 2.0)
        {
            score+=20;
            ringFlag[i]=0;
        }
    }
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
    meter     = Speedometer(3.2,-3.2,0.0,COLOR_RED,COLOR_BLACK);
    bar       = Altbar(-3.2,-3.2,0.0,COLOR_GOLD,COLOR_RED);
    comp      = Compass(0.0,-3.2,0.0,COLOR_CRIMSON,COLOR_GAINSBORO);
    life      = Score(0.0,3.5,COLOR_BLACK);
    for(int i=0;i<12;i++)
    {
        if(i%2==0)
            p[i] = Petrol(rand()%1000,40.0+(rand()%80),rand()%1000,COLOR_RED);
        else
            p[i] = Petrol(rand()%1000,40.0+(rand()%80),-rand()%1000,COLOR_RED);
    }
    for(int i=0;i<32;i++)
    {
        ringFlag[i]=1;

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
        rFlag[i]=5;
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

        // Poll for Keyboard  and mouse events
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
