//bresenham's code line algorithm
#include<GL/glut.h>
#include<stdio.h>

int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
int count = 0;

void init(void)
{
	glClearColor(0, 0, 1, 0); //glClearColor specifies the background color
	gluOrtho2D(-200, 200, -200, 200.0);
}

void plotPoint(float x, float y)
{
	glPointSize(4); //width of the line that is drawing
	//for drawing use glBegin and end 
	glBegin(GL_POINTS);//GL_POINTS Draws points on screen. Every vertex specified is a point.
	glVertex2f(x, y);
	glEnd();
}

void bresLine(int x1, int y1, int x2, int y2)
{

	//plot origin
	glColor3f(2.0f, 0.5f, 1.0f); //FOR LINE COLOR

	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x, y;

	dx = x2 - x1;
	dy = y2 - y1;

	if (dx < 0) {
		dx = -dx;
	}
	if (dy < 0) {
		dy = -dy;
	}
	incx = 1;
	if (x2 < x1) {
		incx = -1;
	}

	incy = 1;
	if (y2 < y1) {
		incy = -1;
	}
	x = x1; y = y1;
	if (dx > dy) {
		plotPoint(x, y);
		e = 2 * dy - dx;
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		for (i = 0; i < dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			plotPoint(x, y);
		}

	}
	else {
		plotPoint(x, y);
		e = 2 * dx - dy;
		inc1 = 2 * (dx - dy);
		inc2 = 2 * dx;
		for (i = 0; i < dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			plotPoint(x, y);
		}
	}

	glFlush();

}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//bresLine(-70, -10, -50, 90); //m > 1 steep,positive
	//bresLine(-10, -70, 90, -50); //m < 1 gentle positive
	bresLine(20, 50, 70, 150);//m>1
	bresLine(60, -100, 30, 50); //m<1

}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow(" Bresenham line by Devashish Agarwal ");
	init();
	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}
