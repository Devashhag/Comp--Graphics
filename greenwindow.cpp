#include<Windows.h>
#include<gl\glut.h>
#include <iostream>

using namespace std;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void init()
{
	glClearColor(0, 1,0, 1); //this is green background
}

int main(int argc, char** argv)

{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);

	glutInitWindowPosition(200, 100);

	glutInitWindowSize(500, 500);

	glutCreateWindow("green window");

	glutDisplayFunc(display);

	init();

	glutMainLoop();

	return 0;

}
