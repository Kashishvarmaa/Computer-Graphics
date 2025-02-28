#include <GLUT/glut.h>

int xc = 0, yc = 0, r = 100; // Circle center (xc, yc) and radius r

// Function to plot points using 8-way symmetry
void plotPoints(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc - x);
    glEnd();
}

// Bresenham's Circle Drawing Algorithm
void drawCircle() {
    int x = 0, y = r;
    int d = 3 - 2 * r; // Decision parameter

    while (x <= y) {
        plotPoints(x, y); // Plot the symmetric points
        x++;

        if (d < 0) {
            d += 4 * x + 6;
        } else {
            y--;
            d += 4 * (x - y) + 10;
        }
    }
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // Set color to white
    glPointSize(2.0); // Set point size
    drawCircle(); // Draw the circle
    glFlush();
}

// Initialize OpenGL settings
void init() {
    glClearColor(1.0, 1.0, 0.0, 1.0); // Set background color to yellow
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200, 200, -200, 200); // Set coordinate system
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham's Circle Algorithm");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}