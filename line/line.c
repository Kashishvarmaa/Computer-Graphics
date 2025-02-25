#include <GL/glut.h>

GLfloat points[][2] = {
    {-0.5, 0.0},  // Start point (Red)
    {0.5, 0.0}    // End point (Blue)
};

GLfloat colors[][3] = {
    {1.0, 0.0, 0.0},  // Red
    {0.0, 0.0, 1.0}   // Blue
};

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_SMOOTH);  // Enable smooth shading for interpolation

    // Remove or fully comment out shadow code
    // glColor3f(0.2, 0.2, 0.2); // This was causing the unwanted grey effect

    // Draw the original line with color interpolation
    glBegin(GL_LINES);
    glColor3f(colors[0][0], colors[0][1], colors[0][2]); // Set color to Red explicitly
    glVertex2f(points[0][0], points[0][1]); // First vertex (start)
    
    glColor3f(colors[1][0], colors[1][1], colors[1][2]); // Set color to Blue explicitly
    glVertex2f(points[1][0], points[1][1]); // Second vertex (end)
    glEnd();

    glFlush(); // Render everything
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Shadow Model with Color Interpolation");

    glClearColor(0.0, 0.0, 0.0, 1.0);  // Set background color to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);  // Set coordinate system

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
