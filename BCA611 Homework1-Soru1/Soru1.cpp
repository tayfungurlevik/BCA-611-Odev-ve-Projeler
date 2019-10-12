
#include <GL/glew.h>
#include <GL/freeglut.h> 

// Drawing routine.
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(10.0, 10.0, 0.0); // Vertex 0
	glVertex3f(30.0, 30.0, 0.0); // Vertex 1
	glVertex3f(90.0, 10.0, 0.0); // Vertex 2
	glVertex3f(70, 30.0, 0.0); // Vertex 3
	glVertex3f(90, 90, 0.0); // Vertex 4
	glVertex3f(70, 70, 0.0); // Vertex 5
	glVertex3f(10, 90.0, 0.0); // Vertex 6
	glVertex3f(30.0, 70.0, 0.0); // Vertex 7
	glVertex3f(10.0, 10.0, 0.0); // Vertex 8 = Vertex 0
	glVertex3f(30.0, 30.0, 0.0); // Vertex 9 = Vertex 1
	glEnd();

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

	glutCreateWindow("Soru 1: Trianglestrip ile kare içinde kare çizimi");

	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}