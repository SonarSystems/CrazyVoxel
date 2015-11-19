#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

using namespace std;

int main( void )
{
    GLFWwindow *window;
    
    /* Initialize the library */
    if ( !glfwInit( ) )
    {
        return -1;
    }
    
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow( 1280, 1280, "Hello World", NULL, NULL );
    
    if ( !window )
    {
        glfwTerminate( );
        return -1;
    }
    
    /* Make the window's context current */
    glfwMakeContextCurrent( window );
    
    glEnable( GL_DEPTH_CLAMP );
    glMatrixMode( GL_PROJECTION );
    //glCullFace( GL_FRONT_AND_BACK );
    glEnable( GL_DEPTH_TEST );
    
    float angle = 0.0f;
    
    /* Loop until the user closes the window */
    while ( !glfwWindowShouldClose( window ) )
    {
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        glLoadIdentity( );
        //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
        
        /* Render OpenGL here */
        /*glPushMatrix();
        glRotatef(angle, 1, 1, 1);
        glBegin( GL_POLYGON );
        // front
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f( -0.5, 0.5, 0.5 );
        glVertex3f( 0.5, 0.5, 0.5 );
        glVertex3f( 0.5, -0.5, 0.5 );
        glVertex3f( -0.5, -0.5, 0.5 );
        glEnd();
        
        glBegin( GL_POLYGON );
        //top
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f( -0.5, 0.5, 0.5 );
        glVertex3f( 0.5, 0.5, 0.5 );
        glVertex3f( 0.5, 0.5, -0.5 );
        glVertex3f( -0.5, 0.5, -0.5 );
        glEnd( );
        
        glBegin( GL_POLYGON );
        //bottom
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f( -0.5, -0.5, 0.5 );
        glVertex3f( 0.5, -0.5, 0.5 );
        glVertex3f( 0.5, -0.5, -0.5 );
        glVertex3f( -0.5, -0.5, -0.5 );
        glEnd( );
        
        glBegin( GL_POLYGON );
        // back
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f( -0.5, 0.5, -0.5 );
        glVertex3f( 0.5, 0.5, -0.5 );
        glVertex3f( 0.5, -0.5, -0.5 );
        glVertex3f( -0.5, -0.5, -0.5 );
        glEnd( );
        
        glBegin( GL_POLYGON );
        //right
        glColor3f(0.3, 0.4, 1.0);
        glVertex3f( 0.5, 0.5, 0.5 );
        glVertex3f( 0.5, -0.5, 0.5 );
        glVertex3f( 0.5, -0.5, -0.5 );
        glVertex3f( 0.5, 0.5, -0.5 );
        glEnd( );
        
        glBegin( GL_POLYGON );
        //left
        glColor3f(0.9, 0.6, 0.76);
        glVertex3f( -0.5, 0.5, 0.5 );
        glVertex3f( -0.5, -0.5, 0.5 );
        glVertex3f( -0.5, -0.5, -0.5 );
        glVertex3f( -0.5, 0.5, -0.5 );
        glEnd( );
        glPopMatrix();*/
        
        /*
         // triangle
        float f[] = {0, 0.5, -0.5, -0.5, -0.5, -0.5, 0.5, -0.5, -0.5};
        
        glEnableClientState( GL_VERTEX_ARRAY );
        glVertexPointer( 3, GL_FLOAT, 0, f );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glDisableClientState( GL_VERTEX_ARRAY );
         */
        
        /*
        // square
        float f[] = {-0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, -0.5, 0.5, -0.5, -0.5, 0.5};
        
        glEnableClientState( GL_VERTEX_ARRAY );
        glVertexPointer( 3, GL_FLOAT, 0, f );
        glDrawArrays( GL_QUADS, 0, 4 );
        glDisableClientState( GL_VERTEX_ARRAY );
        */
        
        // cube
        float f[] =
        {
            -0.5, 0.5, 0.5,
            0.5, 0.5, 0.5,
            0.5, -0.5, 0.5,
            -0.5, -0.5, 0.5,
            -0.5, 0.5, -0.5,
            0.5, 0.5, -0.5,
            0.5, -0.5, -0.5,
            -0.5, -0.5, -0.5
        };
        
        glPushMatrix();
        glRotatef(angle, 1, 1, 1);
        glEnableClientState( GL_VERTEX_ARRAY );
        glVertexPointer( 3, GL_FLOAT, 0, f );
        glDrawArrays( GL_QUADS, 0, 8 );
        glDisableClientState( GL_VERTEX_ARRAY );
        glEnd( );
        
        
/*
        
        glPushMatrix();
        glTranslatef(1, -1, 0);
        glRotatef(0.4, 0, 1, 0);

        glBegin(GL_TRIANGLES); //Begin triangle coordinates
        //Pentagon
        glVertex3f(0.5f, 0.5f, 0.0f);
        glVertex3f(1.5f, 0.5f, 0.0f);
        glVertex3f(0.5f, 1.0f, 0.0f);
        
        glVertex3f(0.5f, 1.0f, 0.0f);
        glVertex3f(1.5f, 0.5f, 0.0f);
        glVertex3f(1.5f, 1.0f, 0.0f);
        
        glVertex3f(0.5f, 1.0f, 0.0f);
        glVertex3f(1.5f, 1.0f, 0.0f);
        glVertex3f(1.0f, 1.5f, 0.0f);
        
        //Triangle
        glVertex3f(-0.5f, 0.5f, -6.0f);
        glVertex3f(-1.0f, 1.5f, 70.0f);
        glVertex3f(-1.5f, 0.5f, 0.0f);
        
        glEnd(); //End triangle coordinates
        glPopMatrix();
 */
        
        //glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
        
        angle += 0.5;

        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        
        /* Poll for and process events */
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}