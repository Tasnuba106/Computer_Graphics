#include<stdio.h>
#include<bits/stdc++.h>
#include<GL/glut.h>
#include<windows.h>

double gx,gy,gvx,gvy,gr;
double yx,yy,yvx,yvy,yr;

struct point
{
double x,y,z;
};

void drawPath(){
glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
{

glVertex3f(-170,-10,0);
glVertex3f(170,-10,0);

}glEnd();

}

void drawCar(double x1, double y1){

glColor3f(0.0,1.0,0.0);
glBegin(GL_LINES);
{

glVertex3f(x1-20.0,y1+30.0,0);
glVertex3f(x1-20.0,y1,0);
glVertex3f(x1-20.0,y1,0);
glVertex3f(x1+80.0,y1,0);

}
glEnd();
glBegin(GL_LINES);
{

glVertex3f(x1+80.0,y1,0);
glVertex3f(x1+60.0,y1+30.0,0);
glVertex3f(x1+60.0,y1+30.0,0);
glVertex3f(x1-20.0,y1+30.0,0);

}
glEnd();

}

void drawCircleWithCoord(double x, double y, double radius)
{
int i;

int segments = 50;
struct point points[100];
glColor3f(0.0,1,0.0);
for(i=0;i&lt;=segments;i++)
{
points[i].x=x+radius*cos(((double)i/(double)segments)*2*pi);
points[i].y=y+radius*sin(((double)i/(double)segments)*2*pi);
}
//draw segments using generated points
glColor3f(1.0,0.0,0.0);
for(i=0;i&lt;segments;i++)
{

glBegin(GL_LINES);
{

glVertex3f(points[i].x,points[i].y,0);
glVertex3f(points[i+1].x,points[i+1].y,0);

}
glEnd();
}
}

void keyboardListener(unsigned char key, int x,int y){}
void specialKeyListener(int key, int x,int y){}
void mouseListener(int button, int state, int x, int y){}

void display(){

//clear the display
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glClearColor(0,0,0,0); //color black
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

/********************
/ set-up camera here
********************/
//load the correct matrix -- MODEL-VIEW matrix
glMatrixMode(GL_MODELVIEW);

//initialize the matrix
glLoadIdentity();

gluLookAt(0,0,200, 0,0,0, 0,1,0);

//again select MODEL-VIEW
glMatrixMode(GL_MODELVIEW);

/****************************
/ Add your objects from here
****************************/
//add objects

drawPath();

//drawTriangleCord(gx, gy, gr);

drawCircleWithCoord(gx, gy, gr);
drawCircleWithCoord(gx+50.0, gy, gr);
//drawCircleWithCoord(yx, yy, yr);

drawCar(gx, gy);

//ADD this line in the end --- if you use double buffer (i.e.
GL_DOUBLE)
glutSwapBuffers();
}

void animate(){
glutPostRedisplay();

if(gx&gt;=160){
//gvx *= -1;
gx=-160;
}

gx+=gvx;

}

void init(){
//codes for initialization

//clear the screen
glClearColor(0,0,0,0);

/************************
/ set-up projection here
************************/
//load the PROJECTION matrix
glMatrixMode(GL_PROJECTION);

//initialize the matrix

glLoadIdentity();

//give PERSPECTIVE parameters
gluPerspective(80, 1, 1, 1000.0);

gx=0.0, gy=0.0;
gvx = 0.05;
gr=10;

}

int main(int argc, char **argv){
glutInit(&amp;argc,argv);
glutInitWindowSize(500, 500);
glutInitWindowPosition(0, 0);
glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
//Depth, Double buffer, RGB color

glutCreateWindow(&quot;My OpenGL Program&quot;);

init();

glEnable(GL_DEPTH_TEST); //enable Depth Testing

glutDisplayFunc(display); //display callback function
glutIdleFunc(animate); //what you want to do in the
idle time (when no drawing is occuring)

glutKeyboardFunc(keyboardListener);
glutSpecialFunc(specialKeyListener);
glutMouseFunc(mouseListener);

glutMainLoop(); //The main loop of OpenGL

return 0;
}
