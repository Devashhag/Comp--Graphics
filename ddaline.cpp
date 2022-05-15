//dda for slope m>1 and m<1
#include<GL/glut.h>
#include<iostream>

void init()
{ // 0 1 0 0 is for the green color 
	glClearColor(0, 0, 1, 0); //glClearColor specifies the background color 
	//The gluOrtho2D function defines a 2-D orthographic projection matrix.
	gluOrtho2D(-200, 200, -200, 200); //where are lines on screen  it also indicates width h and pixel 
	//gluOrtho2D(0, 640, 0, 350);

}

void plotPoint(float x, float y)
{
	glPointSize(4); //width of the line that is drawing
	//for drawing use glBegin and end 
	glBegin(GL_POINTS); //GL_POINTS Draws points on screen. Every vertex specified is a point.
	glVertex2f(x, y);
	glEnd();
}

void ddaLine(int x1, int y1, int x2, int y2)
{

	//glColor3f(2.0f, 0.5f, 1.0f);//Lilac
	glColor3f(2.0f, 0.5f, 1.0f); //FOR LINE COLOR

	//drawing intended line using DDA
	int dx = x2 - x1, dy = y2 - y1, length;
	float xinc, yinc, x = x1, y = y1;

	if (abs(dx) > abs(dy))
		length = abs(dx);
	else
		length = abs(dy);

	xinc = float(dx) / length;
	yinc = float(dy) / length;

	plotPoint(x, y);

	for (int i = 0; i < length; i++)
	{
		x = x + xinc;
		y = y + yinc;
		plotPoint(x, y);
		glFlush();
	}
	printf("%f %f\n", x, y);

}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	ddaLine(20, 50, 70, 150); //slope greater than 1 (M>1)
	ddaLine(60, -100, 30, 50); //slope less than 1 (M<1)
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//glutinitdisplaymode actually inits display mode
   //glutsingle allows for display on single buffer
   //glutrgb gives color
	glutInitWindowPosition(180, 180);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Line Drawing: DDA by Devashish Agarwal");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
