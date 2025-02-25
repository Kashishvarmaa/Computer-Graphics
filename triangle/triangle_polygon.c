#include <GL/glut.h>

// Define an array of points (x, y)
GLfloat points[][2] = {
    {0.0, 0.0}, {0.5, 0.5}, {-0.5, 0.5},
    {0.5, -0.5}, {-0.5, -0.5}, {0.7, 0.2},
};

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0, 0.0, 0.0); // Set point color to red
    glPointSize(5.0); // Set point size
    
    glBegin(GL_POLYGON);
    for (int i = 0; i < sizeof(points) / sizeof(points[0]); i++) {
        glVertex2f(points[i][0], points[i][1]);
    }
    glEnd();
    
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Points Example");
    
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set background color to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set coordinate system
    
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}