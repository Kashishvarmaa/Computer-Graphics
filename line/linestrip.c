#include <GLUT/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.8f, -0.8f);
        glVertex2f(-0.5f, 0.5f);
        glVertex2f(0.0f, -0.5f);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(0.8f, -0.8f);
    glEnd();
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 0.0); // Yellow line strip
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Line Strip");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}