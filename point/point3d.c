#include <GLUT/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPointSize(8.0);
    glBegin(GL_POINTS);
    glVertex3f(0.0f, 0.0f, -5.0f); // 3D point at (0,0,-5)
    glEnd();
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 0.0, 0.0); // Red point
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1.0, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    
    glutInitWindowSize(500, 500);    // Set window size
    glutInitWindowPosition(100, 100); // Set window position
    glutCreateWindow("3D Point");

    init(); 
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}