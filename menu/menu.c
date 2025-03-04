#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <stdlib.h>
#include <stdio.h>


int id = 0;  // Global variable to store menu selection

void point() {
    glBegin(GL_POINTS);
    glVertex2i(100, 100);
    glVertex2i(200, 200);
    glVertex2i(300, 100);
    glEnd();
}

void line() {
    glBegin(GL_LINES);
    glVertex2i(100, 100);
    glVertex2i(200, 200);
    glVertex2i(200, 200);
    glVertex2i(300, 100);
    glVertex2i(300, 100);
    glVertex2i(100, 100);
    glEnd();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    gluOrtho2D(0.0, 400.0, 0.0, 300.0);
}

void mymenu(int value) {
    if (value == 1) 
        exit(0);
    else if (value == 2)
        id = 2;
    else if (value == 3)
        id = 3;
    glutPostRedisplay();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(3.0);
    glPointSize(5.0);
    if (id == 2) 
        point();
    else if (id == 3) 
        line();
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Menu");

    init();
    
    glutDisplayFunc(display);
    glutCreateMenu(mymenu);
    glutAddMenuEntry("Exit", 1);
    glutAddMenuEntry("Point", 2);
    glutAddMenuEntry("Line", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}