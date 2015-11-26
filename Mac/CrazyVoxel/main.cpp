#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>

#include "GLHelper.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

USING_NS_QUAD

void keyCallback( GLFWwindow *window, int key, int scancode, int action, int mods );

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
    
    glfwSetKeyCallback( window, keyCallback );
    glfwSetInputMode( window, GLFW_STICKY_KEYS, 1 );

    
    glViewport( 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT ); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glMatrixMode( GL_PROJECTION ); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glLoadIdentity( ); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    glOrtho( 0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, -1000, 1000 ); // essentially set coordinate system

    glMatrixMode( GL_MODELVIEW ); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    glLoadIdentity( ); // same as above comment
    
    
    // Enable depth test
    glEnable( GL_DEPTH_TEST );
    // Accept fragment if it closer to the camera than the former one
//    glDepthFunc( GL_LESS );
   // glDepthMask(GL_FALSE);
    GLfloat rotation = 0.0f;
    
    // Loop until the user closes the window
    while ( !glfwWindowShouldClose( window ) )
    {
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        
        
        // render OpenGL here
        //DrawHollowCircle( SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 120, 36 );

        
        
        //GLHelper::Shapes::Circle::DrawHollowCircle( SCREEN_WIDTH / 2, SCREEN_HEIGHT *0.75, 0, 60, 36 );
        
        //Shapes::Triangle::DrawTriangle( SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f, 480 );
        
        //Shapes::Triangle::DrawTriangle( 10, 10, 0, 540, 200, 0, 300, 400, 0 );

        GLfloat halfScreenWidth = SCREEN_WIDTH / 2;
        GLfloat halfScreenHeight = SCREEN_HEIGHT / 2;
        
        //GLHelper::Shapes::Hexagon::DrawHexagon(halfScreenWidth, halfScreenHeight, 0.0f, 169, true);
        glPushMatrix();
        
        glRotatef(rotation, 1.0, 1.0, 0.0);
        
        GLHelper::Shapes3D::Cube::DrawCube(halfScreenWidth, halfScreenHeight, 0.0f, 100, true);

        glPopMatrix();
        
        rotation += 0.5;
        
        // Swap front and back buffers
        glfwSwapBuffers( window );
        
        // Poll for and process events
        glfwPollEvents( );
    }
    
    glDisable( GL_DEPTH_TEST );
    
    glfwTerminate( );
    
    return 0;
}

void keyCallback( GLFWwindow *window, int key, int scancode, int action, int mods )
{
    std::cout << key << std::endl;
    
    // actions are GLFW_PRESS, GLFW_RELEASE or GLFW_REPEAT
    if ( key == GLFW_KEY_SPACE && action == GLFW_REPEAT )
    {
        std::cout << "Space Key Pressed" << std::endl;
    }
}


