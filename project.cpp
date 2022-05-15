
// code by DEVASHISH AGARWAL
//500082411
//R214220399
//PROJECT  1 COMPUTER GRAPHICS
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include<cmath>
#include<iostream>
using namespace std;
float shift = 0;
float xr = 0, yr = 0;

float Change_x = 1, Change_y = 1;
//void Project(Float xr, float yr) {}
void Project(float xr, float yr) {
    glClear(GL_COLOR_BUFFER_BIT);

    //lets start with the making of the traingles
    //the triangle 1
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2f(600 + xr, 900 + yr);
    glVertex2f(550 + xr, 800 + yr);
    glVertex2f(650 + xr, 800 + yr);
    glEnd();
    glFlush();

    //the triangle 2
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(550 + xr, 800 + yr);
    glVertex2f(600 + xr, 700 + yr);
    glVertex2f(500 + xr, 700 + yr);
    glEnd();
    glFlush();


    //the triangle 3
    glColor3f(0, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(550 + xr, 800 + yr);
    glVertex2f(650 + xr, 800 + yr);
    glVertex2f(600 + xr, 700 + yr);
    glEnd();
    glFlush();


    //the triangle 4
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(650 + xr, 800 + yr);
    glVertex2f(600 + xr, 700 + yr);
    glVertex2f(700 + xr, 700 + yr);
    glEnd();
    glFlush();


    //the triangle 5
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2f(500 + xr, 700 + yr);
    glVertex2f(450 + xr, 600 + yr);
    glVertex2f(550 + xr, 600 + yr);
    glEnd();
    glFlush();

    //the triangle 6
    glColor3f(0, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(550 + xr, 600 + yr);
    glVertex2f(500 + xr, 700 + yr);
    glVertex2f(600 + xr, 700 + yr);
    glEnd();
    glFlush();


    //the triangle 7
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(550 + xr, 600 + yr);
    glVertex2f(650 + xr, 600 + yr);
    glVertex2f(600 + xr, 700 + yr);
    glEnd();
    glFlush();



    //the triangle 8
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2f(650 + xr, 600 + yr);
    glVertex2f(600 + xr, 700 + yr);
    glVertex2f(700 + xr, 700 + yr);
    glEnd();
    glFlush();


    //the triangle 9
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(700 + xr, 700 + yr);
    glVertex2f(650 + xr, 600 + yr);
    glVertex2f(750 + xr, 600 + yr);
    glEnd();
    glFlush();

    //quad1
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(450 + xr, 600 + yr);
    glVertex2f(400 + xr, 500 + yr);
    glVertex2f(550 + xr, 500 + yr);
    glVertex2f(550 + xr, 600 + yr);
    glEnd();
    glFlush();

    //quad2
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2f(650 + xr, 500 + yr);
    glVertex2f(650 + xr, 600 + yr);
    glVertex2f(750 + xr, 600 + yr);
    glVertex2f(800 + xr, 500 + yr);
    glEnd();
    glFlush();

    //bottomm triangle1

    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2f(550 + xr, 300 + yr);
    glVertex2f(400 + xr, 500 + yr);
    glVertex2f(550 + xr, 500 + yr);
    glEnd();
    glFlush();

    //bottomm triangle2
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2f(650 + xr, 300 + yr);
    glVertex2f(650 + xr, 500 + yr);
    glVertex2f(800 + xr, 500 + yr);
    glEnd();
    glFlush();

    //lets focusing on the inner trinagles


    //inner trinagle 1
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2f(400 + xr, 500 + yr);
    glVertex2f(500 + xr, 500 + yr);
    glVertex2f(450 + xr, 600 + yr);
    glEnd();
    glFlush();

    //inner trinagle 2
    glColor3f(0, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(500 + xr, 500 + yr);
    glVertex2f(450 + xr, 600 + yr);
    glVertex2f(550 + xr, 600 + yr);
    glEnd();
    glFlush();


    //inner trinagle 3
    glColor3f(0, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(650 + xr, 600 + yr);
    glVertex2f(700 + xr, 500 + yr);
    glVertex2f(750 + xr, 600 + yr);
    glEnd();
    glFlush();

    //inner trinagle 4
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(650 + xr, 600 + yr);
    glVertex2f(700 + xr, 500 + yr);
    glVertex2f(650 + xr, 500 + yr);
    glEnd();
    glFlush();



    // the square bottom left 
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(100, 200);
    glVertex2f(300, 200);
    glVertex2f(300, 400);
    glVertex2f(100, 400);
    glEnd();
    glFlush();



    // the square bottom right
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(1410, 200);
    glVertex2f(1600, 200);
    glVertex2f(1600, 400);
    glVertex2f(1410, 400);
    glEnd();
    glFlush();


    // the upper one left square
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(260, 1400);
    glVertex2f(260, 1600);
    glVertex2f(460, 1600);
    glVertex2f(460, 1400);
    glEnd();
    glFlush();

    // the upper one right square
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(1230, 1400);
    glVertex2f(1230, 1600);
    glVertex2f(1430, 1600);
    glVertex2f(1430, 1400);
    glEnd();
    glFlush();



    glutPostRedisplay();
    glutSwapBuffers();


    // the main part of moving and hiiting
    if (xr > 700) {
        Change_x = 0;
        Change_y = 1;
    }
    else if (yr > 550) {
        Change_x = -1;
        Change_y = 0;
        if (xr < -100) {
            Change_x = 0;
            Change_y = -1;
        }

    }
    else if (yr < -100) {
        Change_x = 1;
        Change_y = 0;
        if (xr > 600) {
            Change_x = 0;
            Change_y = 1;
        }

    }


    Project(xr + 10 * Change_x, yr + 10 * Change_y);
}

// function for calling the project
void draw() {
    float xr = 0, yr = 0;
    Project(xr, yr);


}

// if the person does not want to use the computer to play
//up down left right keys work whenever we remove the parameters from the project xr and yr
void specialkey(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
        yr = yr + 1;

        cout << y << endl;
        glutPostRedisplay();
        break;
    case GLUT_KEY_DOWN:
        yr--;
        cout << y << endl;
        glutPostRedisplay();
        break;
    case GLUT_KEY_LEFT:
        xr--;
        cout << x << endl;
        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT:
        xr++;
        cout << x << endl;
        glutPostRedisplay();
        break;

    }


}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowSize(600, 600);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("COMPUTER GRAPHICS PROJECT BY DEVASHISH AGARWAL");


    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1700, 0, 1700);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1, 1, 0, 0);

    glutDisplayFunc(draw);
    // glutDisplayFunc(Project);
    glutSpecialFunc(specialkey);

    glutMainLoop();
    return 0;
}


// CODE BY DEVASHISH AGARWAL

