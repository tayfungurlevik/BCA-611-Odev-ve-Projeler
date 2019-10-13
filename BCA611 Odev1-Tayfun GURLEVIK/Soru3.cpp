#include <GL/glew.h>
#include <GL/freeglut.h>
#define _USE_MATH_DEFINES
#include <math.h>

void CemberCiz(float merkezX, float merkezY, float yaricap, int vertexSayisi)
{
	glBegin(GL_LINE_LOOP);
	for (size_t i = 0; i < vertexSayisi; i++)
	{
		glVertex2f(merkezX + yaricap * cos(i * 2 * M_PI / vertexSayisi), merkezY + yaricap * sin(i * 2 * M_PI / vertexSayisi));
	}

	glEnd();
}

// Drawing routine.
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.0, 0.0);
	int vertex = 10;
	float X = 50.0f;
	float Y = 50.0f;
	float R = 10;
	CemberCiz(X, Y, R, vertex);
	

	glFlush();
}

// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);

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

	glutCreateWindow("Soru 3: Çember çizimi");

	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}