#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <fstream>
const int WIDTH = 640;
const int HEIGHT = 480;
int xNumber = 5;
int yNumber = 5;
void drawPolyLineFile(const char * fileName) {

	std::ifstream inStream;
	inStream.open(fileName);	// open the file
	if(inStream.fail())
		return;
	//glClear(GL_COLOR_BUFFER_BIT);      // clear the screen 
	GLint numpolys, numLines, x ,y;
	inStream >> numpolys;		           // read the number of polylines
	for(int j = 0; j < numpolys; j++)  // read each polyline
	{
		inStream >> numLines;
		glBegin(GL_LINE_STRIP);	     // draw the next polyline
		for (int i = 0; i < numLines; i++)
		{
			inStream >> x >> y;        // read the next x, y pair
			glVertex2i(x, y);
		}
		glEnd();
	}
	glFlush();
	inStream.close();
}

//--------------- setWindow ---------------------
void setWindow(float left, float right, int bottom, int top)
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(left, right, bottom, top); 
}
//---------------- setViewport ------------------
void setViewport(int left, int bottom, int width, int height)
{
glViewport(left, bottom, width, height);
}


void render() {

	glClear(GL_COLOR_BUFFER_BIT);
	
	setWindow(0, WIDTH, 0, HEIGHT);		// set a fixed window
	for (size_t i = 0; i < xNumber; i++)
	{
		for (size_t j = 0; j < yNumber; j++)
		{
			setViewport(i * WIDTH / xNumber, j*HEIGHT/yNumber, WIDTH / xNumber, HEIGHT / yNumber);
			drawPolyLineFile("../dino.dat");		// draw it again
		}
		
	}
	
	glFlush();

}

int main(int argc, char** argv)
{
	glutInit( &argc, argv ); 
	
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
	glutInitWindowSize( 640,480 );
	glutInitWindowPosition( 0, 0 );
	glutCreateWindow( "Soru1" );
	
	glutDisplayFunc( render );;                   
	glutMainLoop();

	return( 0 );

}