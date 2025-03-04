#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float polygonSize = 1.0; // Scale factor for polygon size

void polygon() {
    glPushMatrix();
    glScalef(polygonSize, polygonSize, 1.0); // Scale polygon size
    
    glBegin(GL_POLYGON);
    glVertex2i(100, 100);
    glVertex2i(200, 200);
    glVertex2i(300, 100);
    glVertex2i(250, 50);
    glEnd();
    
    glPopMatrix();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    gluOrtho2D(0.0, 400.0, 0.0, 300.0);
}

void mymenu(int value) {
    if (value == 1) exit(0);
    glutPostRedisplay();
}

// Polygon size control
void modifyPolygonSize(int value) {
    if (value == 0) polygonSize += 0.2; // Increase size
    else if (value == 1) polygonSize -= 0.2; // Decrease size
    glutPostRedisplay();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    polygon();
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Polygon Size Control");

    init();
    glutDisplayFunc(display);

    // Polygon size submenu
    int polygonMenu = glutCreateMenu(modifyPolygonSize);
    glutAddMenuEntry("Increase Size", 0);
    glutAddMenuEntry("Decrease Size", 1);
    
    // Main Menu
    glutCreateMenu(mymenu);
    glutAddSubMenu("Modify Polygon Size", polygonMenu);
    glutAddMenuEntry("Exit", 1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}
