#include <GL/glut.h>

GLfloat points[][2] = {
    {-0.5, 0.0},  // Start point
    {0.5, 0.0}    // End point
};

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0, 0.0, 0.0);  // Red color for the line
    glLineWidth(10.0);           // Set line width
    
    glEnable(GL_LINE_STIPPLE);  // Enable stippling for dotted effect
    glLineStipple(1, 0x0101);   // Dotted pattern

    glBegin(GL_LINES);
    glVertex2f(points[0][0], points[0][1]); // First point
    glVertex2f(points[1][0], points[1][1]); // Second point
    glEnd();

    glDisable(GL_LINE_STIPPLE); // Disable stippling after use

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Dotted Red Line with White Background");

    glClearColor(1.0, 1.0, 1.0, 1.0);  // Set background color to white (1.0, 1.0, 1.0)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);  // Set coordinate system

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}