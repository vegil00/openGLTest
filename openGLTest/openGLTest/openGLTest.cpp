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
#include<vector>
#include<iostream>
using namespace std;
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

	glColor3f(1.0, 0.0, 0.0);  
	//glPointSize(100);// Set line segment color to red
	glBegin(GL_POINTS);

	glVertex3f(100, 75, 0);
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
void strcopy(char* des, char* source, int size)
{
	//if (des != nullptr)
	//{
	//	delete des;
	//	des = nullptr;
	//}
	//*(&des )= new char[size + 1];
	if (des == nullptr || source == nullptr)
	{
		return;
	}
	//for (int i = 0; i < size+1; i++)
	//{
	//	des[i] = source[i];
	//}
	if (des<source || des>source + size + 1)
	{
		while ((*source) != '\0');
			
		{
			*des++ = *(source++);
			} 
		*(des ) = '\0';
	}
	else
	{
		source = source + size-1 ;
		des = des +size-1 ;
		int temp = size;
		while (temp--)
		{
			*des-- = *source--;
			
		}
		des[size + 1] = '\0';
	}
	
	//memcpy(des, source, size+1);
}
int strlength(char* str)

{
	int length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return length;
}
int main(int argc,char* argv[])

{
	vector<int>v;
	//v.insert(v.begin(), 1);
	//glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//glutInitWindowPosition(50, 100);
	//glutInitWindowSize(400, 300);
	//glutCreateWindow("opengl");
	//glClearColor(1.0, 1.0, 1.0, 0);
	//glMatrixMode(GL_PROJECTION);
	//gluOrtho2D(0, 200, 0, 150);
	//glutDisplayFunc(lineSegment);
	//glutMainLoop();
	char* a = "123456";
	char*b=new char;
	strcopy(b, a, strlen(a));
	cout << b << endl;
	cout << strlength(b)<<endl;
	system("pause");
	return 1;
    
}

