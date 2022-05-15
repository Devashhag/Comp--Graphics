#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

int ymin = 1000, ymax = 0, n, x[10], y[10], xi[100], temp;
float slope[100];

void Scanline()
{
    glBegin(GL_LINES);
    for (int i = 0; i < n; i++)
    {
        int dx = x[i + 1] - x[i];
        int dy = y[i + 1] - y[i];
        if (dy == 0)slope[i] = 1.0;
        if (dx == 0)slope[i] = 0.0;
        if (dx != 0 && dy != 0)
            slope[i] = (float)dx / dy;
    }
    for (int j = 0; j <= ymax; j++)
    {
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (((y[i] <= j) && (y[i + 1] > j)) || ((y[i] > j) && (y[i + 1] <= j)))
            {
                xi[k] = (int)(x[i] + slope[i] * (j - y[i]));
                k++;
            }
        }
        for (int m = 0; m < k - 1; m++)
        {
            for (int i = 0; i < k - 1; i++)
            {
                if (xi[i] > xi[i + 1])
                {
                    temp = xi[i];
                    xi[i] = xi[i + 1];
                    xi[i + 1] = temp;
                }
            }
            glColor3f(0, 0, 1);
            for (int i = 0; i < k; i += 2)
            {
                glVertex2f(xi[i], j);
                glVertex2f(xi[i + 1] + 1, j);
            }
        }
    }
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Scanline");

    printf("Enter the number of vertices:");
    scanf_s("%d", &n);
    printf("enter the coordinates of vertices:");
    for (int i = 0; i < n; i++)
    {
        scanf_s("%d%d", &x[i], &y[i]);
        if (y[i] > ymax)
            ymax = y[i];
        if (y[i] < ymin)
            ymin = y[i];
    }
    x[n] = x[0];
    y[n] = y[0];

    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(Scanline);
    glutMainLoop();
    return 0;
}


