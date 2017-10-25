// openGLTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<Windows.h>
//#include<GL\glew.h>
//#include<GL\GL.h>
#include<GL\glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//void lineSegment()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glBegin(GL_LINE);
//	glEnd();
//	glFlush();
//}
//void init()
//{
//	glClearColor(1.0, 1.0, 1.0, 1.0);       // set display-window color to white
//
//	glMatrixMode(GL_PROJECTION);            // set projection parameters
//	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
//}

void lineSegment()
{
	glClear(GL_COLOR_BUFFER_BIT);           // Clear display window

	glColor3f(1.0, 0.0, 0.0);               // Set line segment color to red
	glBegin(GL_LINES);
	glVertex2i(180, 15);
	glVertex2i(10, 145);
	glEnd();

	glFlush();                              // Process all OpenGL routines as quickly as possible
}

//void main(int argc, char ** argv)
//{
//	glutInit(&argc, argv);                  // Initialize GLUT
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // Set display mode
//	glutInitWindowPosition(50, 100);        // Set top-left display-window position
//	glutInitWindowSize(400, 300);           // Set display-window width and height
//	glutCreateWindow("An Example OpenGL Program");      // Create display window
//
//	init();                                 // Execute initialization procedure
//	glutDisplayFunc(lineSegment);           // Send graphics to display window
//	glutMainLoop();                         // Display everything and wait
//}

int main(int argc,char* argv[])

{
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(400, 300);
	glutCreateWindow("opengl");
	glClearColor(1.0, 1.0, 1.0, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 200, 0, 150);
	glutDisplayFunc(lineSegment);
	glutMainLoop();
	system("pause");
	return 1;
    
}

