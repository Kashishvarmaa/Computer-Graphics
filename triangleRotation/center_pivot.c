#include <GLUT/glut.h>
#include <stdio.h>
#include <math.h>

float angle = 0.0;
float pivotX = 0.0, pivotY = 0.0;
int choice;

void applyRotation(float *x, float *y) {
    float rad = angle * M_PI / 180.0;
    float cosA = cos(rad);
    float sinA = sin(rad);
    float newX, newY;
    
    float centerX = (2.0 + 4.0 + 3.0) / 3.0;
    float centerY = (1.0 + 1.0 + 4.0) / 3.0;
    
    if (choice == 1) {
        *x -= centerX;
        *y -= centerY;
    } else if (choice == 2) {
        *x -= pivotX;
        *y -= pivotY;
    }
    
    newX = (*x) * cosA - (*y) * sinA;
    newY = (*x) * sinA + (*y) * cosA;
    
    if (choice == 1) {
        newX += centerX;
        newY += centerY;
    } else if (choice == 2) {
        newX += pivotX;
        newY += pivotY;
    }
    
    *x = newX;
    *y = newY;
}

void drawTriangle(int rotated) {
    float vertices[3][2] = {
        {2.0, 1.0},
        {4.0, 1.0},
        {3.0, 4.0}
    };
    
    if (rotated) {
        for (int i = 0; i < 3; i++) {
            applyRotation(&vertices[i][0], &vertices[i][1]);
        }
    }
    
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 3; i++) {
        glVertex2f(vertices[i][0], vertices[i][1]);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
    // Draw original triangle in white
    glColor3f(1.0, 1.0, 1.0);
    drawTriangle(0);
    
    // Draw rotated triangle in red
    glColor3f(1.0, 0.0, 0.0);
    drawTriangle(1);
    
    glutSwapBuffers();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 5, -1, 5);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    printf("Enter 1 to rotate about the triangle's center or 2 to rotate about a pivot point: ");
    scanf("%d", &choice);
    
    if (choice == 2) {
        printf("Enter pivot point (x y): ");
        scanf("%f %f", &pivotX, &pivotY);
    }
    
    printf("Enter rotation angle: ");
    scanf("%f", &angle);
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotating Triangle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
