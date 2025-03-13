#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

// Function to initialize OpenGL
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set background color to black
}

// Function to handle window resizing
void reshape(int width, int height) {
    glViewport(0, 0, width, height); // Set the viewport to cover the new window
    glMatrixMode(GL_PROJECTION);     // Switch to the projection matrix
    glLoadIdentity();                 // Reset the projection matrix
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set up an orthogonal projection
    glMatrixMode(GL_MODELVIEW);       // Switch back to the modelview matrix
}

// Function to render the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    // Draw a triangle
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0); // Red
        glVertex2f(-0.5, -0.5);

        glColor3f(0.0, 1.0, 0.0); // Green
        glVertex2f(0.5, -0.5);

        glColor3f(0.0, 0.0, 1.0); // Blue
        glVertex2f(0.0, 0.5);
    glEnd();

    glutSwapBuffers(); // Swap the front and back buffers
}


// Main function
int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Enable double buffering and RGB color
    glutInitWindowSize(800, 600);                // Set the window size
    glutCreateWindow("OpenGL Triangle Example"); // Create the window

    // Initialize GLEW
    glewInit();

    // Set up callback functions
    glutDisplayFunc(display); // Register display callback
    glutReshapeFunc(reshape); // Register reshape callback

    // Initialize OpenGL settings
    init();

    // Enter the GLUT event processing loop
    glutMainLoop();

    return 0;
}