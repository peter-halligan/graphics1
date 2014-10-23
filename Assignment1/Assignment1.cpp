// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// A basic OpenGL program displaying a 2D house shape

#include <windows.h>
#include "freeglut.h"
#include "stdio.h"
#include "math.h"
int windowSize = 1000;
int worldSize = 200;
double radius = 10;
double bodyRadius = radius;
double lwr_arm_len = radius;
double upr_arm_len = radius * 1.5;
int arm_width = 3;
bool boundingCircleIsVisisble = true;

double black[] = { 0.0, 0.0, 0.0 };
double colors[] = { 0.0, 0.0, 0.0 };
double red[] = { 1.0, 0.0, 0.0 };
double green[] = { 0.0, 0.0, 1.0 };
double blue[] = { 0.0, 1.0, 0.0 };

void setClippingRectangle(void);
void DrawCircle(float, float, float, int);
void DrawBoundingCircle(float, float, float, int);
void drawSquare(void);
void drawUpperArm(void);
void drawLowerArm(void);
void drawBody(void);
void drawHead(void);
void drawEye(void);
void drawSpider();
void drawBadSpider(double *);

void display(void)
{
	// draw edges of house in red

	// clear all pixels in frame buffer
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	//glTranslatef((-worldSize/2)+20, (worldSize/3)-20 , 0);
	//glRotatef(90, 0, 0, 1);
	drawBadSpider(colors);
	glPopMatrix();
	glFlush();
}

void drawBadSpider(double *colors)
{
	glColor3f(colors[0], colors[1], colors[2]);
	glPointSize(2);
	glPushMatrix();
		drawBody();
		glTranslatef(0, radius + (radius / 2), 0);
		drawHead();
			glPushMatrix();
				glRotatef(-25, 0, 0, 1);
				glTranslatef(0, (radius / 2) + (radius / 10), 0);
				drawEye();
			glPopMatrix();
			glRotatef(25, 0, 0, 1);
			glTranslatef(0, (radius / 2) + (radius / 10), 0);
			drawEye();
	// draw first leg
	glPopMatrix();
	glPushMatrix();
		DrawBoundingCircle(0, 0, radius * 2, 360);
	glPopMatrix();
	glPushMatrix();
		glColor3f(1.0, 0.0, 0.0);
		glTranslatef(radius *.9, 0, 0);
		drawUpperArm();
	// draw lower leg
		glTranslatef((upr_arm_len*.43), 0, 0);
		glRotatef(-45, 0, 0, 1);
		drawLowerArm();
	glPopMatrix();
	//leg 2
	glPushMatrix();
		glRotatef(-45, 0, 0, 1);
		glTranslatef(radius*.9, 0, 0);
		drawUpperArm();
		glTranslatef((upr_arm_len*.43), 0, 0);
		glRotatef(-45, 0, 0, 1);
		drawLowerArm();
	glPopMatrix();
	//leg3
	glPushMatrix();
		glRotatef(45, 0, 0, 1);
		glTranslatef(radius*.9, 0, 0);
		drawUpperArm();
		glTranslatef(upr_arm_len*.43, 0, 0);
		glRotatef(-45, 0, 0, 1);
		drawLowerArm();
	glPopMatrix();
	//le4
	glPushMatrix();
		glTranslatef((radius + upr_arm_len / 2) * -1, 0, 0);
		drawUpperArm();
		glTranslatef(upr_arm_len *.1, 0, 0);
		glRotatef(225, 0, 0, 1);
		drawLowerArm();
	glPopMatrix();
	//leg5
	glPushMatrix();
	glRotatef(45, 0, 0, 1);
	glTranslatef(upr_arm_len / 2 * -1, 0, 0);
	drawUpperArm();
	glTranslatef(((upr_arm_len / 2) + (lwr_arm_len / 2))* -1, 0, 0);
	drawLowerArm();
	glPopMatrix();
	//leg6
	glPushMatrix();
	glRotatef(-45, 0, 0, 1);
	glTranslatef(upr_arm_len / 2 * -1, 0, 0);
	drawUpperArm();
	glTranslatef(((upr_arm_len / 2) + (lwr_arm_len / 2))* -1, 0, 0);
	drawLowerArm();
	glPopMatrix();
}

void drawSpider()
{
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(2);
	glPushMatrix();
	drawBody();
	glTranslatef(0, radius + (radius / 2), 0);
	drawHead();
	glPushMatrix();
	glRotatef(-25, 0, 0, 1);
	glTranslatef(0, (radius / 2) + (radius / 10), 0);
	drawEye();
	glPopMatrix();
	glRotatef(25, 0, 0, 1);
	glTranslatef(0, (radius / 2) + (radius / 10), 0);
	drawEye();
	// draw first leg
	glPopMatrix();
	glPushMatrix();
	glTranslatef(upr_arm_len / 2, 0, 0);
	drawUpperArm();
	// draw lower leg
	glTranslatef((upr_arm_len / 2) + (lwr_arm_len / 2), 0, 0);
	drawLowerArm();
	glPopMatrix();
	//leg 2
	glPushMatrix();
	glRotatef(-45, 0, 0, 1);
	glTranslatef(upr_arm_len / 2, 0, 0);
	drawUpperArm();
	glTranslatef((upr_arm_len / 2) + (lwr_arm_len / 2), 0, 0);
	drawLowerArm();
	glPopMatrix();
	//leg3
	glPushMatrix();
	glRotatef(45, 0, 0, 1);
	glTranslatef(upr_arm_len / 2, 0, 0);
	drawUpperArm();
	glTranslatef((upr_arm_len / 2) + (lwr_arm_len / 2), 0, 0);
	drawLowerArm();
	glPopMatrix();
	//le4
	glPushMatrix();
	glTranslatef(upr_arm_len / 2 * -1, 0, 0);
	drawUpperArm();
	glTranslatef(((upr_arm_len / 2) + (lwr_arm_len / 2))* -1, 0, 0);
	drawLowerArm();
	glPopMatrix();
	//leg5
	glPushMatrix();
	glRotatef(45, 0, 0, 1);
	glTranslatef(upr_arm_len / 2 * -1, 0, 0);
	drawUpperArm();
	glTranslatef(((upr_arm_len / 2) + (lwr_arm_len / 2))* -1, 0, 0);
	drawLowerArm();
	glPopMatrix();
	//leg6
	glPushMatrix();
	glRotatef(-45, 0, 0, 1);
	glTranslatef(upr_arm_len / 2 * -1, 0, 0);
	drawUpperArm();
	glTranslatef(((upr_arm_len / 2) + (lwr_arm_len / 2))* -1, 0, 0);
	drawLowerArm();
	glPopMatrix();
}
void init(void)
{
	// select clearing color (for glClear)
	glClearColor(1.0, 1.0, 1.0, 0.0);	// RGB-value for white
	setClippingRectangle();
	// initialize view (simple orthographic projection)

}
void drawEye(void)
{
	glPushMatrix();
	glScalef(.1, .1, 0);
	DrawCircle(0, 0, radius, 360);
	glPopMatrix();
}
void drawBody(void)
{
	glPushMatrix();
	DrawCircle(0, 0, radius, 360);
	glPopMatrix();
}
void drawHead(void)
{
	glPushMatrix();
	glScalef(.5, .5, 0);
	DrawCircle(0, 0, radius, 360);
	glPopMatrix();
}
void DrawBoundingCircle(float cx, float cy, float r, int num_segments)
{
	if (boundingCircleIsVisisble)
	{
		glBegin(GL_LINE_LOOP);
		for (int ii = 0; ii < num_segments; ii++)
		{
			float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 

			float x = r * cosf(theta);//calculate the x component 
			float y = r * sinf(theta);//calculate the y component 

			glVertex2f(x + cx, y + cy);//output vertex 

		}
		glEnd();
	}
	else
	{
	}
}
void DrawCircle(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_TRIANGLE_FAN);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 

		glVertex2f(x + cx, y + cy);//output vertex 

	}
	glEnd();
}
void drawSquare(void)
{
	glPointSize(10);

	glBegin(GL_POLYGON);
		glVertex3f(0, .5, 0);
		glVertex3f(.5, .5, 0);
		glVertex3f(.5, -.5, 0);
		glVertex3f(0, -.5, 0);
	glEnd();

}
void drawLowerArm()
{
	glPushMatrix();
	glScalef(lwr_arm_len, arm_width, 0);
	drawSquare();
	glPopMatrix();
}
void drawUpperArm()
{
	
	glPushMatrix();
	glScalef(upr_arm_len, arm_width, 0);
	drawSquare();
	glPopMatrix();
}

void setClippingRectangle(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLdouble halfWorldWidth = worldSize / 2;
	GLdouble halfWorldHeight = worldSize / 3;
	gluOrtho2D(-halfWorldWidth, halfWorldWidth, -halfWorldHeight, halfWorldHeight);
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 48:
		glClearColor(1.0, 1.0, 1.0, 1.0);
		glutPostRedisplay();
		break;
	case 49:
		glClearColor(0.0, 1.0, 0.0, 1.0);
		glutPostRedisplay();
		break;
	case 50:
		glClearColor(0.0, 0.0, 1.0, 1.0);
		glutPostRedisplay();
		break;
	case 51:
		glClearColor(0.45, 0.1, .48, 1.0);
		glutPostRedisplay();
		break;
	case 52:
		for (int i = 0; i < 3; i++)
		{
			colors[i] = red[i];
		}
		drawBadSpider(colors);
		glutPostRedisplay();
		break;
	case 53:
		for (int i = 0; i < 3; i++)
		{
			colors[i] = green[i];
		}
		drawBadSpider(colors);
		glutPostRedisplay();
		break;
	case 54:
		for(int i = 0; i < 3; i++)
		{
			colors[i] = blue[i];
		}
		drawBadSpider(colors);
		glutPostRedisplay();
		break;
	case 57:
		for (int i = 0; i < 3; i++)
		{
			colors[i] = black[i];
		}
		drawSpider();
		glutPostRedisplay();
		break;
	default:
		break;
	}
}


// create a single buffered colour window
int main(int argc, char** argv)
{
	int windowWidth = windowSize / 2;
	int windowHeight = windowSize / 2;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("spiderPigGame");
	init();						// initialise view
	glutDisplayFunc(display);		// draw scene
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

