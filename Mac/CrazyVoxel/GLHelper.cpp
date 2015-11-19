//
//  GLHelper.cpp
//  GLHelper
//
//  Created by Sonar Systems on 19/11/2015.
//  Copyright © 2015 Sonar Systems. All rights reserved.
//

#include "GLHelper.h"

void GLHelper::Shapes::DrawCircle( GLfloat xPos, GLfloat yPos, GLfloat zPos, GLfloat radius, GLint numberOfSides )
{
    GLint numberOfVertices = numberOfSides + 2;
    
    GLfloat doublePi = 2.0f * M_PI;
    
    GLfloat vertices[numberOfVertices * 3];
    vertices[0] = xPos;
    vertices[1] = yPos;
    vertices[2] = zPos;
    
    for ( int i = 1; i < numberOfVertices; i++ )
    {
        vertices[i * 3] = xPos + ( radius * cos( i * doublePi / numberOfSides ) );
        vertices[( i * 3 ) + 1] = yPos + ( radius * sin( i * doublePi / numberOfSides ) );
        vertices[( i * 3 ) + 2] = zPos;
    }
    
    glEnableClientState( GL_VERTEX_ARRAY );
    glVertexPointer( 3, GL_FLOAT, 0, vertices );
    glDrawArrays( GL_TRIANGLE_FAN, 0, numberOfVertices );
    glDisableClientState( GL_VERTEX_ARRAY );
}



void GLHelper::Shapes::DrawHollowCircle( GLfloat xPos, GLfloat yPos, GLfloat zPos, GLfloat radius, GLint numberOfSides )
{
    GLint numberOfVertices = numberOfSides + 1;
    
    GLfloat doublePi = 2.0f * M_PI;
    
    GLfloat vertices[numberOfVertices * 3];
    
    for ( int i = 0; i < numberOfVertices; i++ )
    {
        vertices[i * 3] = xPos + ( radius * cos( i * doublePi / numberOfSides ) );
        vertices[( i * 3 ) + 1] = yPos + ( radius * sin( i * doublePi / numberOfSides ) );
        vertices[( i * 3 ) + 2] = zPos;
    }
    
    glEnableClientState( GL_VERTEX_ARRAY );
    glVertexPointer( 3, GL_FLOAT, 0, vertices );
    glDrawArrays( GL_LINE_STRIP, 0, numberOfVertices );
    glDisableClientState( GL_VERTEX_ARRAY );
}

