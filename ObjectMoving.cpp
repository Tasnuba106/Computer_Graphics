#include<stdio.h>
#include<bits/stdc++.h>
#include<GL/glut.h>
#include<windows.h>

#define pi (2*acos(0.0))

double gx,gy,gvx,gvy,gr;
double yx,yy,yvx,yvy,yr;

struct point
{
double x,y,z;
};

void drawAxis(){
glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
{

glVertex3f(-100,0,0);
glVertex3f(100,0,0);

}glEnd();
glBegin(GL_LINES);
{

glVertex3f(0,-100,0);
glVertex3f(0,100,0);

}glEnd();
}

void drawTriangleCord(double x1, double y1, double r){
double x2=x1+r;
double x3= (x1+x2)/2.0;
double y2=y1;
double y3= y1+50.0;
glColor3f(1.0,0.0,0.0);
glBegin(GL_TRIANGLES);
{
glVertex3f(x1-10,y1,0);
glVertex3f(x2-10,y2,0);
glVertex3f(x3-10,y3,0);

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
for(i=0;i&lt;segments;i++)

{
glColor3f(1.0,0.0,0.0);

glBegin(GL_LINES);
{

glVertex3f(points[i].x,points[i].y,0);
glVertex3f(points[i+1].x,points[i+1].y,0);

}
glEnd();
}
}

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

drawTriangleCord(gx, gy, gr);
drawCircleWithCoord(gx+5, gy+20, gr-10);
drawCircleWithCoord(yx, yy, yr);
drawTriangleCord(yx-5, yy-20, gr);

drawAxis();

//ADD this line in the end --- if you use double buffer (i.e.
GL_DOUBLE)
glutSwapBuffers();
}

void animate(){
glutPostRedisplay();
if(gx&gt;=80 || gx&lt;=-80){
gvx *= -1;
}
if(yy&gt;=80 || yy&lt;=-80){
yvy *= -1;
}
gx+=gvx;

yy+=yvy;

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
gvx = 0.01;
gr=30;
yx=0.0, yy=0.0;
yvy = 0.01;
yr=20;

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

glutMainLoop(); //The main loop of OpenGL

return 0;
}