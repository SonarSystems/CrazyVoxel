#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>

#include "GLHelper/GLHelper.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480



void keyCallback( GLFWwindow *window, int key, int scancode, int action, int mods );

GLfloat translationX = 0.0f;
GLfloat translationY = 0.0f;

int main( void )
{
    GLFWwindow *window;
    
    // Initialize the library
    if ( !glfwInit( ) )
    {
        return -1;
    }
    //glfwWindowHint(GLFW_SAMPLES, 2); // antialiasing
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
    
    GLfloat halfScreenWidth = SCREEN_WIDTH / 2;
    GLfloat halfScreenHeight = SCREEN_HEIGHT / 2;
    
    GLHelper::Shapes3D::Cube cube;
    cube.SetCenterPosition(halfScreenWidth, halfScreenHeight, 0);
    cube.SetEdgeLength( 250);
    cube.SetColour(COLOUR_YELLOW);
    cube.SetWireframe(true);
    
    
    std::cout << cube.GetColourGreen() << std::endl;
    
    // Loop until the user closes the window
    while ( !glfwWindowShouldClose( window ) )
    {
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        

        
        
        glPushMatrix();
        glTranslatef(halfScreenWidth, halfScreenHeight, 0);
        //glRotatef(rotation, 1, 1, 1);
        glRotatef( translationX, 1, 0, 0 );
        glRotatef( translationY, 0, 1, 0 );
        glTranslatef(-halfScreenWidth, -halfScreenHeight, 0);
        
        //GLHelper::Shapes3D::Cube::DrawCube(halfScreenWidth, halfScreenHeight, 0.0f, 150, WIREFRAME_ON, COLOUR_RED );
        //cube.Draw();
        
        GLHelper::Shapes2D::Circle circle;
        circle.SetRadius( 175 );
        circle.SetColour(COLOUR_GREEN);
        circle.SetWireframe(true);
        circle.SetCenterPosition(halfScreenWidth, halfScreenHeight, 0);
        circle.Draw( );
        glPopMatrix();
        
        
        rotation += 2;
        
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
    //std::cout << key << std::endl;
    
    const GLfloat rotationSpeed = 10;
    
    // actions are GLFW_PRESS, GLFW_RELEASE or GLFW_REPEAT
    if ( action == GLFW_PRESS || action == GLFW_REPEAT )
    {
        switch ( key )
        {
            case GLFW_KEY_UP:
                translationX -= rotationSpeed;
                break;
            case GLFW_KEY_DOWN:
                translationX += rotationSpeed;
                break;
            case GLFW_KEY_RIGHT:
                translationY += rotationSpeed;
                break;
            case GLFW_KEY_LEFT:
                translationY -= rotationSpeed;
                break;
        }
        
        
    }
}


