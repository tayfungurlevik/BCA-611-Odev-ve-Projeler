

#include <cstdlib>
#include <cmath>
#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h> 




// Globals.
static float angle = 0.0f;
static unsigned int dikdortgen; // List index.

// Initialization routine.
void setup(void)
{


	dikdortgen = glGenLists(1); // Return a list index.

	// Begin create a display list.
	glNewList(dikdortgen, GL_COMPILE);

	// Draw a rectangle.

	glBegin(GL_POLYGON);
	glColor3f(0, 1.0, 1.0);
	glVertex3f(-40, -40, 0);
	glColor3f(1.0, 0, 0);
	glVertex3f(40, -40, 0);
	glColor3f(0, 0, 1.0);
	glVertex3f(40, 40, 0);
	glColor3f(0, 1.0, 0);
	glVertex3f(-40, 40, 0);
	glEnd();

	glEndList();



	// End create a display list.

	glClearColor(1.0, 1.0, 1.0, 0.0);
}

// Drawing routine.
void drawScene(void)
{

	glClear(GL_COLOR_BUFFER_BIT );// Clear window.

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(angle, 0, 1, 0);

	glCallList(dikdortgen); // Execute display list.
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 0, -0.0001f);
	glRotatef(angle, 0, 0, 1);

	glCallList(dikdortgen); // Execute display list.
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 0, 0.0001f);
	glRotatef(angle, 1, 0, 0);

	glCallList(dikdortgen); // Execute display list.
	glPopMatrix();


	glFlush();

}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50, 50, -50, 50, -50, 100);

	/*glFrustum(-5.0, 5.0, -5.0, 5.0, 5, 100.0);
	gluLookAt(0, 0, 50, 0, 0, 0, 0, 1, 0);*/
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
		glTranslatef(0, 0, 0);
		glRotatef(angle, 0, 1, 0);

		glCallList(dikdortgen); // Execute display list.
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 0, -0.0001f);
		glRotatef(angle, 0, 0, 1);

		glCallList(dikdortgen); // Execute display list.
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 0, 0.0001f);
		glRotatef(angle, 0, 0, 0);

		glCallList(dikdortgen); // Execute display list.
		glPopMatrix();
		glutPostRedisplay();
		break;
	case '-':
		angle -= 1;

		glPushMatrix();
		glTranslatef(0, 0, 0);
		glRotatef(angle, 0, 1, 0);

		glCallList(dikdortgen); // Execute display list.
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 0, -0.0001f);
		glRotatef(angle, 0, 0, 1);

		glCallList(dikdortgen); // Execute display list.
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 0, 0.0001f);
		glRotatef(angle, 0, 0, 0);

		glCallList(dikdortgen); // Execute display list.
		glPopMatrix();
		glutPostRedisplay();
		break;
	default:
		break;
	}
}
void AciklamaYazdir()
{
	std::cout << "Nesneleri x,y,z dondurmek icin +/- tuslarina basili tutunuz." << std::endl;
}
// Main routine.
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	AciklamaYazdir();

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Soru1_A");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();
	

	setup();

	glutMainLoop();
}
