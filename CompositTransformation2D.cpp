#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <GL/glut.h>
using namespace std;

int pntX1, pntY1, choice = 0, edges, pivotX, pivotY;
vector<int> pntX;
vector<int> pntY;
double angle,angleRad;
double scaleX, scaleY;




double round(double d)
{
	return floor(d + 0.5);
}

void drawAxis(){
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
        {
			glVertex3f(-1000,0,0);
			glVertex3f(1000,0,0);
        }glEnd();
    glBegin(GL_LINES);
        {
			glVertex3f(0,-1000,0);
			glVertex3f(0,1000,0);
        }glEnd();
}

void drawPolygon()
{
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(pntX[i], pntY[i]);
	}
	glEnd();
}



void drawPolygonRotationPivot(double angleRad)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(round((pntX[i] * cos(angleRad)) - (pntY[i] * sin(angleRad)-(pivotX*cos(angleRad))+(pivotY*sin(angleRad))+pivotX)),round((pntX[i] * sin(angleRad)) + (pntY[i] * cos(angleRad)-(pivotX*sin(angleRad))-(pivotY*cos(angleRad))+pivotY)));
	}
	glEnd();
}

void drawPolygonRotation(double angleRad)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(round((pntX[i] * cos(angleRad)) - (pntY[i] * sin(angleRad))), round((pntX[i] * sin(angleRad)) + (pntY[i] * cos(angleRad))));
	}
	glEnd();
}

void drawPolygonScale(double x, double y)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(round(pntX[i] * x), round(pntY[i] * y));
	}
	glEnd();
}


void drawPolygonScalePivot(double x, double y)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(round((pntX[i] * x)-((pivotX*x)+pivotX)), round((pntY[i] * y)-((pivotY*y)+pivotY)));
	}
	glEnd();
}

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-640.0, 640.0, -480.0, 480.0);
}


void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
        drawAxis();

    if (choice == 1)
	{
		drawPolygon();
		drawPolygonScale(scaleX, scaleY);
		drawPolygonScalePivot(scaleX, scaleY);
	}
	else if (choice == 2)
	{
		drawPolygon();
		drawPolygonRotation(angleRad);
		drawPolygonRotationPivot(angleRad);
	}

glFlush();
	}




int main(int argc, char** argv)
{

	cout << "Enter your choice:\n\n" << endl;

	cout << "1. Scaling" << endl;
	cout << "2. Rotation" << endl;


	cin >> choice;

	cout << "\n\nFor Polygon:\n" << endl;

	cout << "Enter no of edges: "; cin >> edges;

	for (int i = 0; i < edges; i++)
	{
		cout << "Enter co-ordinates for vertex  " << i + 1 << " : "; cin >> pntX1 >> pntY1;
		pntX.push_back(pntX1);
		pntY.push_back(pntY1);
	}


	if (choice == 1)
	{   cout << "Enter the pivot point: "; cin >> pivotX>>pivotY;
		cout << "Enter the scaling factor for X and Y: "; cin >> scaleX >> scaleY;
	}
	else if (choice == 2)
	{
        cout << "Enter the pivot point: "; cin >> pivotX>>pivotY;
		cout << "Enter the angle for rotation: "; cin >> angle;
		angleRad = angle * 3.1416 / 180;
	}

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Extended Basic Transformations");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();

}
