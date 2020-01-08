

#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <GL/freeglut.h> 
#include <glm.hpp>
#include <gtc/random.hpp>

using namespace std;

float RandomSayiUret(float min, float max)
{
	float output = min + (rand() % static_cast<int>(max - min + 1));
	return output;
}
vector<glm::vec3> noktalar;
// Drawing routine.
void drawScene(void)
{
	
	
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLoadIdentity();
	for (size_t i = 0; i < 20; i++)
	{
		glPushMatrix();
		glTranslatef(noktalar[i].x,noktalar[i].y,noktalar[i].z);
		glScalef(1.0, 1.0, 1.0);
		glutWireSphere(1, 10, 10);
		glPopMatrix();
	}

	glFlush();
}

// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	for (size_t i = 0; i < 20; i++)
	{
		glm::vec3 random_nokta;
		random_nokta.x = RandomSayiUret(-100.0f, 100.0f);
		random_nokta.y = RandomSayiUret(-100.0f, 100.0f);
		random_nokta.z = RandomSayiUret(-100.0f, 100.0f);
		noktalar.push_back(random_nokta);
	}
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(-100, -100, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100, 100, -100, 100, -100, 200);

	glMatrixMode(GL_MODELVIEW);
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
	glutCreateWindow("Odev4.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}

