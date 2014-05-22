#ifdef __APPLE__
#include "GLUT/glut.h"
#include "OpenGL/gl.h"
#else
#include "GL/freeglut.h"
#include "GL/gl.h"
#endif

#include <cstdlib>
#include "RenshiApp.h"

static int windowId;

void onRender()
{
    RenshiApp::getInstance().onRender();
}

void onKeyPressed(unsigned char key, int x, int y)
{
	RenshiApp::getInstance().onKeyPressed(key, x, y);
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
