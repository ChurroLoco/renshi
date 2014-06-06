#include "RenshiApp.h"
#include <iostream>

#ifdef __APPLE__
#include "GLUT/glut.h"
#include "OpenGL/gl.h"
#else
#include "GL/freeglut.h"
#include "GL/gl.h"
#endif

using namespace std;

RenshiApp& RenshiApp::getInstance()
{
	static RenshiApp instance;
	return instance;
}

RenshiApp::RenshiApp()
{
	cout << "Creating RenshiApp instance...\n";
	this->m_cameraPosX = 0.0f;
}

RenshiApp::~RenshiApp()
{
	cout << "Destroying RenshiApp instance...\n";
}

void RenshiApp::onRender()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glOrtho(this->m_cameraPosX - 1.0,this->m_cameraPosX + 1.0, -1.0, 1.0, -1.0, 1.0);

	glBegin(GL_POLYGON);
		glVertex2f(-0.5, -0.5);
		glVertex2f(-0.5, 0.5);
		glVertex2f(0.5, 0.5);
		glVertex2f(0.5, -0.5);
	glEnd();
	glutSwapBuffers();
}

void RenshiApp::onKeyPressed(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'q':
		case 27:
			std::exit(EXIT_SUCCESS);
	}
}

void RenshiApp::onSpecialKeyPressed(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_LEFT:
		  this->m_cameraPosX += 0.001f;
		  glutPostRedisplay();
		  break;
		case GLUT_KEY_RIGHT:
		  this->m_cameraPosX -= 0.001f;
		  glutPostRedisplay();
		  break;
	}
}
