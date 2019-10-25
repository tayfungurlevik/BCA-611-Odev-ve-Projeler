///////////////////////////////////////////////////////////        
// helixList.cpp
//
// This program draws several helixes using a display list.
// 
// Sumanta Guha.
///////////////////////////////////////////////////////////

#include <cstdlib>
#include <cmath>
#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h> 


static float angle = 0.0f;
// Globals.
static unsigned int aHelix; // List index.
void timer(int angle)
{
	/* update animation */
	glPushMatrix();
	glRotatef(angle, 1, 0, 0);
	glTranslatef(0.0, 0.0, -10.0);
	
	glCallList(aHelix); // Execute display list.
	glPopMatrix();
	angle += 5;
	glutPostRedisplay();
	
	glutTimerFunc(1000.0 / 60.0, timer, angle);
}
// Initialization routine.
void setup(void)
{
	float t; // Angle parameter.

	aHelix = glGenLists(1); // Return a list index.

	// Begin create a display list.
	glNewList(aHelix, GL_COMPILE);

	// Draw a rectangle.
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0, 1.0, 1.0);
	glVertex3f(-40, -40, 0);
	glColor3f(1.0, 0, 0);
	glVertex3f(50, -40, 0);
	glColor3f(0, 0, 1.0);
	glVertex3f(50, 80, 0);
	glColor3f(0, 1.0, 0);
	glVertex3f(-40, 80, 0);
	glEnd();

	glEndList();
	// End create a display list.

	glClearColor(1.0, 1.0, 1.0, 0.0);
}

// Drawing routine.
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	
	glPushMatrix();
	glRotatef(angle, 1, 0, 0);
	glTranslatef(0.0, 0.0,0);

	glCallList(aHelix); // Execute display list.
	glPopMatrix();

	

	glFlush();
	
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-100.0, 100.0, -100.0, 100.0, 5, 250.0);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case '+':
		angle += 1;
		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(angle, 1, 0, 0);
		

		glCallList(aHelix); // Execute display list.
		glPopMatrix();
		glutPostRedisplay();
	default:
		break;
	}
}

// Main routine.
int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("helixList.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);
	//glutTimerFunc(1, timer, 1);
	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}
