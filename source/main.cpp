#ifdef __APPLE__
#include "GLUT/glut.h"
#include "OpenGL/gl.h"
#else
#include "GL/freeglut.h"
#include "GL/gl.h"
#endif

#include <cstdlib>
static int windowId;

void onRender()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-0.5, -0.5);
        glVertex2f(-0.5, 0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.5, -0.5);
    glEnd();
    glutSwapBuffers();
}

void onKeyPressed(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'q':
		case 27:
			std::exit(EXIT_SUCCESS);
	}	
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
	glutEnterGameMode();
    glutKeyboardFunc(onKeyPressed);
	glutDisplayFunc(onRender);
    glutMainLoop();    
    return 0;
}
