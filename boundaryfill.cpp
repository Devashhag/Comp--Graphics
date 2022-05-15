#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

void getPixel(int x, int y, float pixels[3])
{
    glFlush();
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, pixels);
}

void bf4(int x, int y, float newc[3], float bounc[3])
{
    float color[3] = { 0,0,0 };
    getPixel(x, y, color);
    if ((color[0] != newc[0] || color[1] != newc[1] || color[2] != newc[2]) && (color[0] != bounc[0]) || (color[1] != bounc[1]) || (color[2] != bounc[2]))
    {
        glBegin(GL_POINTS);
        glColor3fv(newc);
        glVertex2f(x, y);
        glEnd();
        glFlush();
        bf4(x + 1, y, newc, bounc);
        bf4(x - 1, y, newc, bounc);
        bf4(x, y + 1, newc, bounc);
        bf4(x, y - 1, newc, bounc);
    }
}



void Floodfill()
{
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 1);
    glVertex2f(200, 200);
    glVertex2f(300, 200);
    glVertex2f(300, 300);
    glVertex2f(200, 300);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1, 1, 0);
    glVertex2f(200, 200);
    glVertex2f(300, 200);
    glVertex2f(300, 200);
    glVertex2f(300, 300);
    glVertex2f(300, 300);
    glVertex2f(200, 300);
    glVertex2f(200, 300);
    glVertex2f(200, 200);
    glEnd();
    glFlush();
    float bounc[3] = { 1.0,1.0,0.0 }, newc[3] = { 0.0,1.0,0.0 };
    bf4(250, 250, newc, bounc);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Boundaryfill");


    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(Floodfill);
    glutMainLoop();
    return 0;
}

