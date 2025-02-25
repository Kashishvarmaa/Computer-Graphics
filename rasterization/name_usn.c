#include <GLUT/glut.h>  // Include the GLUT library for OpenGL functions
#include <string.h>      // Include string library for handling C-string functions

// Function to display text using OpenGL rasterization
void displayText(float x, float y, const char* text) {
    glRasterPos2f(x, y);  // Set the position (x, y) for where to render the text on the screen
    // Loop through each character in the string and render it
    for (int i = 0; i < strlen(text); i++) {
        // Render each character at the current position with the chosen font
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);  
    }
}

// Display function for OpenGL
void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer to prepare the screen for rendering

    glColor3f(0.0, 0.0, 0.0);  // Set the text color to black (RGB values)

    // Call displayText to render text at different positions
    // These are hardcoded positions for the text
    displayText(-0.15, 0.1, "Name: Kashish Varma");  // Name text
    displayText(-0.15, 0.0, "USN: 1RVU22CSE039");   // USN text
    displayText(-0.15, -0.1, "Section: A section"); // Section text

    glFlush();  // Ensures all OpenGL commands are executed and rendered on the screen
}

// Initialization function
void init() {
    glClearColor(0.7, 0.7, 0.85, 1.0);  // Set the background color to lavender (RGB values)

    glMatrixMode(GL_PROJECTION);   // Set the current matrix mode to projection matrix
    glLoadIdentity();              // Reset the projection matrix to identity
    gluOrtho2D(-1, 1, -1, 1);      // Set an orthographic 2D projection matrix with coordinates from -1 to 1
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);                        // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   // Set display mode to single-buffered and RGB color
    glutInitWindowSize(500, 500);                  // Set window size to 500x500 pixels
    glutCreateWindow("Name USN and Section");        // Create a window with the title 

    init();                                       // Call the initialization function
    glutDisplayFunc(display);                     // Register the display function to render the scene
    glutMainLoop();                               // Enter the GLUT main loop, where the program will continuously render

    return 0;  // Return 0 to indicate successful execution
}