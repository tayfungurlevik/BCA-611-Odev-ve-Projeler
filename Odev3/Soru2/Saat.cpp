

#include <cmath>
#include <iostream>
#include <ctime>
#include <GL/glew.h>
#include <GL/freeglut.h> 
#include <glm.hpp>
#define PI 3.14159265358979324


void ArcCizdir(float x,float y,float yaricap,float baslangicAcisi,float bitisAcisi,float increment,glm::vec2* baslangicNoktasi,glm::vec2*bitisNoktasi)
{
	glBegin(GL_LINE_STRIP);
	for (float theta = baslangicAcisi; theta <= bitisAcisi; theta += increment)
	{

		//x = r * Math.Cos (theta);
		//y = r * Math.Sin (theta);
		if (theta==baslangicAcisi)
		{
			baslangicNoktasi->x = x + yaricap * cos(theta);
			baslangicNoktasi->y = y + yaricap * sin(theta);
		}
		if (theta== bitisAcisi)
		{
			bitisNoktasi->x = x + yaricap * cos(theta);
			bitisNoktasi->y = y + yaricap * sin(theta);
		}
		glVertex2f(x + yaricap * cos(theta), y + yaricap * sin(theta));
	}
	glEnd();
}
void ArcCizdir(float x, float y, float yaricap, float baslangicAcisi, float bitisAcisi, float increment)
{
	glBegin(GL_LINE_STRIP);
	for (float theta = baslangicAcisi; theta <= bitisAcisi; theta += increment)
	{

		//x = r * Math.Cos (theta);
		//y = r * Math.Sin (theta);
		
		glVertex2f(x + yaricap * cos(theta), y + yaricap * sin(theta));
	}
	glEnd();
}


// Drawing routine.
void drawScene(void)
{
	glm::vec2  V4,V7, V10, V11;
	glm::vec2 V9;
	V9.x = 50; V9.y = 55;
	glm::vec2 V8;
	V8.x = 30; V8.y = 60;
	
	V7.x = 30; V7.y = 50;
	glm::vec2 V5;
	V5.x = 70; V5.y = 60;
	glm::vec2 E3 = V7 - V8;
	glm::vec2 E4 = V9 - V8;
	float theta2 = acos(glm::dot(E3, E4) / (glm::length(E3) * glm::length(E4)));

	glClear(GL_COLOR_BUFFER_BIT);
	//Saatin sol ust yayinin cizimi
	float r = 10;
	float start_angle = 3*PI/2;
	float end_angle = start_angle+theta2;
	glColor3f(1, 0, 0);
	glLineWidth(3.0f);
	ArcCizdir(V8.x, V8.y, r, start_angle, end_angle, PI / 1000,&V7,&V10);
	//Saatin duz kenarlarinin cizimi
	glBegin(GL_LINES);
	
	glVertex3f(10, 10, 0);//V1
	glVertex3f(90,10, 0);//V2
	glVertex3f(90, 10, 0);//V2
	glVertex3f(90, 50, 0);//V3
	glVertex3f(10, 10, 0);//V1
	glVertex3f(10, 50, 0);//V6
	glVertex3f(10, 50, 0);//V6
	glVertex3f(30, 50, 0);//V7
	glVertex3f(90, 50, 0);//V3
	glVertex3f(70, 50, 0);//V4
	glEnd();
	//Saatin sag ust yayinin cizimi
	ArcCizdir(V5.x,V5.y, r, 3 * PI / 2-theta2, 3*PI/2, PI / 1000,&V11,&V4);
	//saatin orta ust yayinin cizimi
	glm::vec2 E1 = V10 - V9;
	glm::vec2 E2 = V11 - V9;
	float theta1 = acos(glm::dot(E1, E2) / (glm::length(E1) * glm::length(E2)));
	float r2=glm::length(V8 - V9) - r;
	ArcCizdir(V9.x, V9.y, r2, PI / 2 - theta2, PI - (PI / 2 - theta2), PI / 1000, &V11, &V10);
	//ic dairenin cizimi
	glLineWidth(1.0f);
	ArcCizdir(V9.x, V9.y, r2 - 2, 0, 2 * PI, PI / 1000);
	//Akrep ve yelkovanin cizimi
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm,&now);
	//std::cout << ltm.tm_hour << ltm.tm_min << std::endl;
	//Akrep ve yelkovanin cizimi
	glPushMatrix();
	glTranslatef(V9.x,V9.y,0);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	float akrepUzunlugu = r2 - 8;
	glVertex3f(sin(glm::radians(((float)ltm.tm_hour * 30))) * akrepUzunlugu, cos(glm::radians((float)ltm.tm_hour*30)) * akrepUzunlugu, 0);
	float yelkovanUzunlugu = r2 - 6;
	glVertex3f(0, 0, 0);
	glVertex3f(sin(glm::radians((float)ltm.tm_min * 6)) * yelkovanUzunlugu, cos(glm::radians((float)ltm.tm_min)*6) * yelkovanUzunlugu, 0);
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
	glutCreateWindow("Saat.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}
