#ifdef __APPLE__
#include "GLUT/glut.h"
#include "OpenGL/gl.h"
#else
#include "GL/freeglut.h"
#include "GL/gl.h"
#endif

#include <cstdlib>
#include "Application.h"

static int windowId;

void onRender()
{
  Application::getInstance().onRender();
}

void onKeyPressed(unsigned char key, int x, int y)
{
	Application::getInstance().onKeyPressed(key, x, y);
}

void onSpecialKeyPressed(int key, int x, int y)
{
	Application::getInstance().onSpecialKeyPressed(key, x, y);
}

int main(int argc, char** argv)
{
 	// Setup GLUT window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(500,500);
 	glutInitWindowPosition(100,100);
	glutEnterGameMode();
	
  	// Setup GLUT callback methods for the main window
	glutKeyboardFunc(onKeyPressed);
	glutSpecialFunc(onSpecialKeyPressed);
	glutDisplayFunc(onRender);
	glutIgnoreKeyRepeat(true);
	glutMainLoop();
	return 0;
}
