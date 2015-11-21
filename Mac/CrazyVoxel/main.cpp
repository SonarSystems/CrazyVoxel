#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>

#include "GLHelper.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

USING_NS_TRIANGLE


int main( void )
{
    GLFWwindow *window;
    
    // Initialize the library
    if ( !glfwInit( ) )
    {
        return -1;
    }
    
    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow( SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL );
    
    if ( !window )
    {
        glfwTerminate( );
        return -1;
    }
    
    // Make the window's context current
    glfwMakeContextCurrent( window );
    
    glViewport( 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT ); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glMatrixMode( GL_PROJECTION ); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glLoadIdentity( ); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    glOrtho( 0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1 ); // essentially set coordinate system
    glMatrixMode( GL_MODELVIEW ); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    glLoadIdentity( ); // same as above comment
    
    // Loop until the user closes the window
    while ( !glfwWindowShouldClose( window ) )
    {
        glClear( GL_COLOR_BUFFER_BIT );
        
        // render OpenGL here
        //DrawHollowCircle( SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 120, 36 );

        
        
        //GLHelper::Shapes::Circle::DrawHollowCircle( SCREEN_WIDTH / 2, SCREEN_HEIGHT *0.75, 0, 60, 36 );
        
        //Shapes::Triangle::DrawTriangle( SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f, 480 );
        
        //Shapes::Triangle::DrawTriangle( 10, 10, 0, 540, 200, 0, 300, 400, 0 );
        GLfloat vertices[] = { 30, 50, 0,
            200, 400, 0,
            619, 10, 0 };
        
        DrawTriangle(vertices);
        
        
        // Swap front and back buffers
        glfwSwapBuffers( window );
        
        // Poll for and process events
        glfwPollEvents( );
    }
    
    glfwTerminate( );
    
    return 0;
}


