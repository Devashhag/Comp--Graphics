#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int r;
float nX1, nX2, nX3, nY1, nY2, nY3, choose;
float mx, my, tx, ty, sx, sy;
float X1, X2, X3, Y1, Y2, Y3;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(-20, 0);
    glVertex2i(20, 0);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(0, -20);
    glVertex2i(0, 20);
    glEnd();
    //POLYGON
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(X1, Y1);
    glVertex2f(X2, Y2);
    glVertex2f(X3, Y3);
    glEnd();

    {
        //REFLECTION
        X1 = X1;
        X2 = X2;
        X3 = X3;
        Y1 = -Y1;
        Y2 = -Y2;
        Y3 = -Y3;

    }
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(X1, Y1);
    glVertex2f(X2, Y2);
    glVertex2f(X3, Y3);
    glEnd();
    glFlush();
}
void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);
}
int main(int argc, char** argv) {
    printf("Enter the X1 co-ordinate : ");
    scanf_s("%f", &X1);
    printf("Enter the Y1 co-ordinate : ");
    scanf_s("%f", &Y1);
    printf("Enter the X2 co-ordinate : ");
    scanf_s("%f", &X2);
    printf("Enter the Y2 co-ordinate : ");
    scanf_s("%f", &Y2);
    printf("Enter the X3 co-ordinate : ");
    scanf_s("%f", &X3);
    printf("Enter the Y3 co-ordinate : ");
    scanf_s("%f", &Y3);

    printf("reflection of the given triangle ->");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(600, 600);
    glutCreateWindow("2-D ");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

