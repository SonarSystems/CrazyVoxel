//
//  GLHelper.hpp
//  GLHelper
//
//  Created by Sonar Systems on 19/11/2015.
//  Copyright © 2015 Sonar Systems. All rights reserved.
//

#ifndef GLHelper_h
#define GLHelper_h

// ASSUMES YOU HAVE GLEW AND GLFW SETUP

#include <GL/glew.h>
#include <math.h>

// shortcut for using namespace GLHelper;
#define USING_NS_GLH using namespace GLHelper;
// shortcut for using namespace Shapes;
#define USING_NS_SHAPES using namespace Shapes;

namespace GLHelper
{
    namespace Shapes
    {
        /**
         * Draw A Circle
         * @param xPos x-axis coordinate for the center of the circle
         * @param yPos y-axis coordinate for the center of the circle
         * @param zPos z-axis coordinate for the center of the circle
         * @param radius circle radius
         * @param numberOfSides how many sides does the circle have
         */
        void DrawCircle( GLfloat xPos, GLfloat yPos, GLfloat zPos, GLfloat radius, GLint numberOfSides );
        
        /**
         * Draw A Hollow Circle
         * @param xPos x-axis coordinate for the center of the circle
         * @param yPos y-axis coordinate for the center of the circle
         * @param zPos z-axis coordinate for the center of the circle
         * @param radius circle radius
         * @param numberOfSides how many sides does the circle have
         */
        void DrawHollowCircle( GLfloat xPos, GLfloat yPos, GLfloat zPos, GLfloat radius, GLint numberOfSides );
    }
}

#endif /* GLHelper_hpp */
