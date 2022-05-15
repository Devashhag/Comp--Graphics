#include <gl/glut.h>
#include <stdio.h>
int x1, y1, x2, y2, x3, y3, x4, y4;
void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
void drawP()
{
	glPointSize(1.0);
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(x3, y3);
	glVertex2i(x4, y4);
	glEnd();
}
void draw_curve() {
	drawP();
	double u, x, y;
	draw_pixel(x1, y1);
	draw_pixel(x4, y4);
	for (u = 0.01; u <= 1; u += 0.01)
	{
		x = (1 - u) * (1 - u) * (1 - u) * x1 + 3 * u * (1 - u) * (1 - u) * x2 + 3 * u * u * (1 - u) * x3 + u * u * u * x4;
		y = (1 - u) * (1 - u) * (1 - u) * y1 + 3 * u * (1 - u) * (1 - u) * y2 + 3 * u * u * (1 - u) * y3 + u * u * u * y4;
		draw_pixel(x, y);
	}
}
void myDisplay() {
	draw_curve();
	glFlush();
}

int main(int argc, char** argv) {

	printf("Enter (x1, y1, x2, y2,x3,y3,x4,y4)\n");
	scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Cubic Bezier Curve");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}

