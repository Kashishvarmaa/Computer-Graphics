#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the window

    glColor3f(1.0, 0.0, 0.0);  // Set the triangle color to red

    glBegin(GL_TRIANGLES);  // Begin drawing a triangle
    glVertex2f(-0.5, -0.5);  // First vertex (bottom-left)
    glVertex2f( 0.5, -0.5);  // Second vertex (bottom-right)
    glVertex2f( 0.0,  0.5);  // Third vertex (top-center)
    glEnd();  // End the drawing

    glFlush();  // Render everything
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Red Triangle");

    glClearColor(1.0, 1.0, 1.0, 1.0);  // Set background color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);  // Set coordinate system

    glutDisplayFunc(display);  // Register the display function
    glutMainLoop();  // Start the main loop
    return 0;
}