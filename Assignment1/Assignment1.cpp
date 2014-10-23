// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//Assignment1

#include <windows.h>
#include "freeglut.h"
#include "stdio.h"
#include "math.h"
#include "variables.h"
#include "functionPrototypes.h"

struct spider Enemy[5];
struct spider hero;

void initialaize(void)
{

	Enemy[0].x = (-worldSize / 2) + (radius * 2.5);
	Enemy[0].y = (worldSize / 2) - (radius * 2.5);
	Enemy[0].heading = RIGHT;

	Enemy[1].x = (-worldSize / 2) + (radius * 2.5);
	Enemy[1].y = (worldSize / 5);
	Enemy[1].heading = RIGHT;

	Enemy[2].x = (-worldSize / 2) + (radius * 2.5);
	Enemy[2].y = 0;
	Enemy[2].heading = RIGHT;

	Enemy[3].x = (-worldSize / 2) + (radius * 2.5);
	Enemy[3].y = (-worldSize / 5);
	Enemy[3].heading = RIGHT;

	Enemy[4].x = (-worldSize / 2) + (radius * 2.5);
	Enemy[4].y = (-worldSize / 2) + (radius * 2.5);
	Enemy[4].heading = RIGHT;

	hero.x = 0;
	hero.y = (-worldSize / 2) + (radius * 2.5);
	hero.heading = 0;

	for (int j = 0; j < 3; j++)
	{
		hero.colour[j] = black[j];
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Enemy[i].colour[j] = red[j];
		}
	}
}
void display(void)
{

	// clear all pixels in frame buffer
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (easy)
	{
		for (int i = 0; i < 5; i+=2)
		{
			glPushMatrix();
			glTranslatef(Enemy[i].x, Enemy[i].y, 0);
			glRotatef(Enemy[i].heading, 0, 0, 1);
			drawSpider(Enemy[i].colour);
			glPopMatrix();
		}
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			glPushMatrix();
			glTranslatef(Enemy[i].x, Enemy[i].y, 0);
			glRotatef(Enemy[i].heading, 0, 0, 1);
			drawSpider(Enemy[i].colour);
			glPopMatrix();
		}
	}
	glPushMatrix();
	glTranslatef(hero.x, hero.y, 0);
	glRotatef(hero.heading, 0, 0, 1);
	drawSpider(hero.colour);
	glPopMatrix();
	glFlush();
}

void drawSpider(float *colors)
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
		DrawBoundingCircle(0, 0, radius * 2, 360,colors);
	glPopMatrix();
	glPushMatrix();
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
		glTranslatef(upr_arm_len *.1  , 0, 0);
		glRotatef(225, 0, 0, 1);
		drawLowerArm();
	glPopMatrix();
	//leg5
	glPushMatrix();
		glRotatef(45, 0, 0, 1);
		glTranslatef(((radius *.9) + upr_arm_len / 2) * -1, 0, 0);
		drawUpperArm();
		glTranslatef(upr_arm_len *.1, 0, 0);
		glRotatef(225, 0, 0, 1);
		drawLowerArm();
	glPopMatrix();
	//leg6
	glPushMatrix();
		glRotatef(-45, 0, 0, 1);
		glTranslatef(((radius*.9) + upr_arm_len / 2) * -1, 0, 0);
		drawUpperArm();
		glTranslatef(upr_arm_len *.1, 0, 0);
		glRotatef(225, 0, 0, 1);
		drawLowerArm();
	glPopMatrix();
}


void init(void)
{
	// select clearing color (for glClear)
	glClearColor(1.0, 1.0, 1.0, 0.0);	// RGB-value for white
	setClippingRectangle();
	// initialize view (simple orthographic projection)
	initialaize();
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
void DrawBoundingCircle(float cx, float cy, float r, int num_segments, float * colour)
{

	if (boundingCircleIsVisible)
	{
		glColor3f(black[0], black[1], black[2]);
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
	glColor3f(colour[0], colour[1], colour[2]);
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
	GLdouble halfWorldHeight = worldSize / 2;
	gluOrtho2D(-halfWorldWidth, halfWorldWidth, -halfWorldHeight, halfWorldHeight);
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case RESETBKG:
		glClearColor(1.0, 1.0, 1.0, 1.0);
		glutPostRedisplay();
		break;
	case GREENBKG:
		glClearColor(0.0, .4, 0.0, 1.0);
		glutPostRedisplay();
		break;
	case BLUEBKG:
		glClearColor(0.0, 0.0, 1.0, 1.0);
		glutPostRedisplay();
		break;
	case PURPLEBKG:
		glClearColor(0.45, 0.1, .48, 1.0);
		glutPostRedisplay();
		break;
	case REDSPIDER:
		for (int j = 0; j < 5; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				Enemy[j].colour[i] = red[i];
			}
		}
		glutPostRedisplay();
		break;
	case GREENSPIDER:
		for (int j = 0; j < 5; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				Enemy[j].colour[i] = green[i];
			}
		}
		glutPostRedisplay();
		break;
	case BLUESPIDER:
		for (int j = 0; j < 5; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				Enemy[j].colour[i] = blue[i];
			}
		}
		glutPostRedisplay();
		break;
	case RESET:
		for (int i = 0; i < 3; i++)
		{
			colors[i] = red[i];
		}
		glutPostRedisplay();
		break;
	case MODE:
		if (easy == true)
		{
			easy = false;
		}
		else
		{
			easy = true;
		}
		glutPostRedisplay();
		break;
	case SHOWCIRCLE:
		if (boundingCircleIsVisible)
		{
			boundingCircleIsVisible = false;
		}
		else
		{
			boundingCircleIsVisible = true;
		}
		glutPostRedisplay();
		break;
	case FORWARD:
		if (hero.x + (radius * 2) < (worldSize /2 ) && hero.x - (radius*2) > (-worldSize /2))
		{
			hero.x += radius * -sinf(hero.heading * M_PI / 180);
			hero.y += radius * cosf(hero.heading * M_PI / 180);
		}
		else
		{
			hero.heading *= -1;
			hero.x += radius * -sinf(hero.heading * M_PI / 180);
			hero.y += radius * cosf(hero.heading * M_PI / 180);
		}
		glutPostRedisplay();
		break;
	case MOVELEFT:
		hero.heading += radius;
		glutPostRedisplay();
		break;
	case MOVERIGHT:
		hero.heading -= radius;
		glutPostRedisplay();
		break;
	case BACKWARDS:
		if (hero.x + (radius * 2) < (worldSize / 2) && hero.x - (radius * 2) > (-worldSize / 2))
		{
			hero.x -= radius * -sinf(hero.heading * M_PI / 180);
			hero.y -= radius * cosf(hero.heading * M_PI / 180);
		}
		else
		{
			hero.heading *= -1;
			hero.x -= radius * -sinf(hero.heading * M_PI / 180);
			hero.y -= radius * cosf(hero.heading * M_PI / 180);
		}
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

