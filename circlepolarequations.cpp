// making an circle using polar equation

#include<gl/glut.h>
#include<math.h>
#include<iostream>
void init() {
	glClearColor(1, 1, 1, 1);
	gluOrtho2D(0, 500, 0, 500);
}

void Circle() {
	float theta, x = 250, y = 250, r = 150; //center coordinates (x,y) theta for the angle  r radius
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES); //CIRCLE USING LINES
	//glBegin(GL_TRIANGLES);
	for (int i = 0; i <= 360; i++) {
		theta = i * 3.142 / 180; //theta color
		glColor3f(1, 0, 0); //circle color
		glVertex2f(x + r * cos(theta), y + r * sin(theta));
	}//for loop  to repeat the lines


	glEnd();
	glFlush();

}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(400, 400);
	glutCreateWindow("  circle using polar equation by devashish agarwal ");
	init();
	glutDisplayFunc(Circle);
	glutMainLoop();
	return 0;
}
