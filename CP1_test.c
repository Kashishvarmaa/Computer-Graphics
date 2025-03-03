#include <GLUT/glut.h>  // OpenGL Utility Toolkit header for OpenGL functions
#include <stdio.h>      // Standard input/output header for handling user input

// Initialize the center coordinates (centerX, centerY) and radius of the circle
int centerX = 250, centerY = 250, radius;

// Function to plot points using 8-way symmetry for drawing a circle
void plotPoints(int x, int y)
{
    glBegin(GL_POINTS);  // Start drawing points
    
    // Plot points in all 8 octants based on symmetry
    glVertex2i(centerX + x, centerY + y);  // First octant
    glVertex2i(centerX - x, centerY + y);  // Second octant
    glVertex2i(centerX + x, centerY - y);  // Third octant
    glVertex2i(centerX - x, centerY - y);  // Fourth octant
    glVertex2i(centerX + y, centerY + x);  // Fifth octant
    glVertex2i(centerX - y, centerY + x);  // Sixth octant
    glVertex2i(centerX + y, centerY - x);  // Seventh octant
    glVertex2i(centerX - y, centerY - x);  // Eighth octant
    
    glEnd();  // End drawing points
}

// Bresenham's Circle Drawing Algorithm to calculate and draw the circle
void drawCircle()
{
    int x = 0, y = radius;  // Start at the top of the circle
    int decision = 3 - (2 * radius);  // Initial decision parameter for Bresenham's algorithm

    // Loop to calculate points until x equals or exceeds y
    while (x <= y)
    {
        plotPoints(x, y);  // Plot the points based on symmetry
        x++;  // Increment x
        
        // Update the decision parameter for the next iteration
        if (decision < 0)
            decision += 4 * x + 6;  // If the decision parameter is less than 0, move horizontally
        else
        {
            y--;  // If the decision parameter is greater than or equal to 0, move diagonally
            decision += 4 * (x - y) + 10;  // Update the decision parameter for diagonal movement
        }
    }
    glFlush();  // Render the points to the screen
}

// OpenGL display function to render the circle
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the screen
    drawCircle();  // Call the function to draw the circle
}

// OpenGL initialization function to set up the environment
void init()
{
    glClearColor(1.0, 1.0, 0.0, 1.0); // Set background color to yellow
    glColor3f(0.0, 0.0, 0.0);  // Set drawing color to black (RGB values)
    glPointSize(2.0);  // Set point size to make the circle visible
    glMatrixMode(GL_PROJECTION);  // Set the matrix mode to projection for 2D rendering
    glLoadIdentity();  // Reset the projection matrix to the identity matrix
    gluOrtho2D(0, 500, 0, 500);  // Set up the orthographic projection with 2D coordinates (0 to 500 on both axes)
}

// Main function where the program starts
int main(int argc, char** argv)
{
    printf("Enter the radius: ");  // Prompt the user for input
    scanf("%d", &radius);  // Read the radius from the user

    glutInit(&argc, argv);  // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Set display mode to single-buffered and RGB color
    glutInitWindowSize(500, 500);  // Set the window size to 500x500 pixels
    glutInitWindowPosition(100, 100);  // Set the window position on the screen
    glutCreateWindow("Bresenham's Circle Drawing Algorithm");  // Create a window with a title
    
    init();  // Call the initialization function
    glutDisplayFunc(display);  // Register the display function to render the circle
    glutMainLoop();  // Enter the GLUT main loop for continuous rendering

    return 0;  // Return 0 to indicate successful execution
}
