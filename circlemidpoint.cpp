//making a circle using mid point

#include<GL/glut.h>
#include<math.h>

void init() {

	//glClearColor(0, 0, 1, 0);
	gluOrtho2D(-300, 300, -300, 300);//where are lines on screen  it also indicates width h and pixel 

}
void putpixel(float xcircle, float ycircle) {
	glColor3f(0, 0, 1);
	glBegin(GL_POINTS);
	glVertex2f(xcircle, ycircle);
	glEnd();
	glFlush();

}

void drawCircle(float xcircle, float ycircle) {

	float x = xcircle;
	float r = ycircle;
	float y = r;
	float d = 5 / 4 - r;
	while (x <= y) {
		putpixel(x, y);
		putpixel(y, x);
		putpixel(0 - x, 0 - y);
		putpixel(0 - y, 0 - x);
		putpixel(0 - x, y);
		putpixel(x, 0 - y);
		putpixel(y, 0 - x);
		putpixel(0 - y, x);

		if (d < 0) {
			d = d + (2 * x) + 1;
		}
		else {
			d = d + 2 * (x - y) + 1;
			y = y - 1;
		}
		x = x + 1;

	}
}


void Circle() {

	drawCircle(0, 200);
	glFlush();

}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(180, 180);
	glutInitWindowSize(400, 400);
	glutCreateWindow("  circle by devashish agarwal ");
	init();
	glutDisplayFunc(Circle);
	glutMainLoop();
	return 0;
}

