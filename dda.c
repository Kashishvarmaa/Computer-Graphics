#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GLUT/glut.h>

int x0 = 10, y0 = 20, xEnd = 300, yEnd = 400;

void setPixel(int x, int y) {
    glColor3f(1.0, 0.0, 0.0);  // Set color to red
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void lineDDA(int x0, int y0, int xEnd, int yEnd) {
    int dx = xEnd - x0, dy = yEnd - y0, steps, k;
    float xIncrement, yIncrement, x = x0, y = y0;

    steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
    xIncrement = dx / (float)steps;
    yIncrement = dy / (float)steps;

    for (k = 0; k <= steps; k++) {
        setPixel(round(x), round(y));
        x += xIncrement;
        y += yIncrement;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    lineDDA(x0, y0, xEnd, yEnd);
    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);  // White background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);  // Set coordinate system to match window size
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("DDA Line Algorithm");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}