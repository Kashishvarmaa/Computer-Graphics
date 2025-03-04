#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int id = 0;

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

void polygonWithoutColor() {
    glBegin(GL_POLYGON);
    glVertex2i(100, 100);
    glVertex2i(200, 200);
    glVertex2i(300, 100);
    glVertex2i(250, 50);
    glEnd();
}

void polygonWithColor() {
    glColor3f(0.0, 1.0, 0.0); // Green color
    glBegin(GL_POLYGON);
    glVertex2i(100, 100);
    glVertex2i(200, 200);
    glVertex2i(300, 100);
    glVertex2i(250, 50);
    glEnd();
    glColor3f(1.0, 0.0, 0.0); // Reset color to red for other shapes
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    gluOrtho2D(0.0, 400.0, 0.0, 300.0);
}

void submenu(int value) {
    id = value;
    glutPostRedisplay();
}

void mymenu(int value) {
    if (value == 1) 
        exit(0);
    glutPostRedisplay();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // Default red color

    glLineWidth(3.0);
    glPointSize(5.0);
    
    if (id == 2) 
        point();
    else if (id == 3) 
        line();
    else if (id == 4)
        polygonWithoutColor();
    else if (id == 5)
        polygonWithColor();
    
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Menu with Submenu");

    init();
    glutDisplayFunc(display);
    
    int draw_submenu_id = glutCreateMenu(submenu);
    glutAddMenuEntry("Point", 2);
    glutAddMenuEntry("Line", 3);
    glutAddMenuEntry("Polygon Without Color", 4);
    glutAddMenuEntry("Polygon With Color", 5);
    
    glutCreateMenu(mymenu);
    glutAddSubMenu("Draw", draw_submenu_id);
    glutAddMenuEntry("Exit", 1);
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}