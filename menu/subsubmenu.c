#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int id = 0;       // Stores the selected shape (Point = 2, Line = 3, Circle = 4)
int fillPoint = 0, fillLine = 0, fillCircle = 0; // Fill modes for each shape

void point() {
    glBegin(fillPoint ? GL_QUADS : GL_POINTS);
    if (fillPoint) {
        glVertex2i(95, 95);
        glVertex2i(105, 95);
        glVertex2i(105, 105);
        glVertex2i(95, 105);
    } else {
        glVertex2i(100, 100);
        glVertex2i(200, 200);
        glVertex2i(300, 100);
    }
    glEnd();
}

void line() {
    if (fillLine) {
        glBegin(GL_QUADS);
        glVertex2i(100, 100);
        glVertex2i(105, 100);
        glVertex2i(205, 205);
        glVertex2i(200, 200);
        
        glVertex2i(200, 200);
        glVertex2i(205, 205);
        glVertex2i(305, 105);
        glVertex2i(300, 100);
    } else {
        glBegin(GL_LINES);
        glVertex2i(100, 100);
        glVertex2i(200, 200);
        glVertex2i(200, 200);
        glVertex2i(300, 100);
        glVertex2i(300, 100);
        glVertex2i(100, 100);
    }
    glEnd();
}

void circle() {
    float cx = 200.0, cy = 150.0, r = 50.0;
    int num_segments = 100;

    glBegin(fillCircle ? GL_TRIANGLE_FAN : GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * M_PI * i / num_segments;
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    gluOrtho2D(0.0, 400.0, 0.0, 300.0);
}

void mymenu(int value) {
    if (value == 1) exit(0);
    glutPostRedisplay();
}

// Shape selection functions
void drawPoint(int value) { id = 2; fillPoint = value; glutPostRedisplay(); }
void drawLine(int value) { id = 3; fillLine = value; glutPostRedisplay(); }
void drawCircle(int value) { id = 4; fillCircle = value; glutPostRedisplay(); }

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(3.0);
    glPointSize(5.0);
    
    if (id == 2) point();
    else if (id == 3) line();
    else if (id == 4) circle();
    
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Menu with Fill Options");

    init();
    glutDisplayFunc(display);

    // Creating Fill submenus for each shape
    int pointFillMenu = glutCreateMenu(drawPoint);
    glutAddMenuEntry("Outline Only", 0);
    glutAddMenuEntry("Fill Color", 1);

    int lineFillMenu = glutCreateMenu(drawLine);
    glutAddMenuEntry("Outline Only", 0);
    glutAddMenuEntry("Fill Color", 1);

    int circleFillMenu = glutCreateMenu(drawCircle);
    glutAddMenuEntry("Outline Only", 0);
    glutAddMenuEntry("Fill Color", 1);

    // Creating Draw submenus with Fill options
    int drawSubmenu = glutCreateMenu(mymenu);
    glutAddSubMenu("Draw Point", pointFillMenu);
    glutAddSubMenu("Draw Line", lineFillMenu);
    glutAddSubMenu("Draw Circle", circleFillMenu);

    // Creating Main Menu
    glutCreateMenu(mymenu);
    glutAddSubMenu("Draw", drawSubmenu);
    glutAddMenuEntry("Exit", 1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}