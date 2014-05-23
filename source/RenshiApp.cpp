#include "RenshiApp.h"
#include <iostream>

RenshiApp& RenshiApp::getInstance()
{
	static RenshiApp instance;
	return instance;
}

RenshiApp::RenshipApp()
{
	cout << "Creating RenshiApp instance...\n";
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
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
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


